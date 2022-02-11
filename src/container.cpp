#include <iostream>
#include <string>
#include <log_file.h>
#include <data.h>
#include <command_line_handlder.h>
#include <i_data_file.h>
#include <container.h>
#include <sensor_data_file.h>
#include <binary_packet_file.h>
#include <error_message.h>


Container :: Container(int args, char* argv[]) {
    commandLineHandler = new CommandLineHandler(args, argv);
    logFile = new LogFile(commandLineHandler->getInputFileName(),
                                        commandLineHandler->getOputputFileName());
    
    if (!commandLineHandler->isInputTXT()) {
        input = new SensorDataFile(commandLineHandler->getInputFileName(),
                                        logFile);
        output = new BinaryPacketFile(commandLineHandler->getOputputFileName(),
                                        logFile);
    }
    else {
        if (commandLineHandler->onSortingMode()) {
            IMessage *msg = new ErrorMessage("06", "Cannot sort with binary packet file input.");
            logFile->addMessage(msg);
            error = true;
            return;
        }
        else{
            input = new BinaryPacketFile(commandLineHandler->getInputFileName(),
                                        logFile);
            output = new SensorDataFile(commandLineHandler->getOputputFileName(),
                                        logFile);
        }
    }
}

LogFile* Container :: getLogFile() {
    return logFile;
}

void Container :: transfer() {
    if (!commandLineHandler->isValidCommand()) {
        logFile->addMessage(commandLineHandler->getMsg());
        error = true;
        return;
    }
    if (input->canReadData()) {
        data = input->readData();
        if (output->isFileExist()) {
            if (!output->warningFileExit()) {
                error = true;
                IMessage *msg = new ErrorMessage("07", "Output file exists.");
                logFile->addMessage(msg);
                return;
            }
        }
        if (commandLineHandler->onSortingMode()){
            data->sort(commandLineHandler->getSortType(), commandLineHandler->getSortOrder());
        }
        output->getSaveString(data);

        output->save();
    }
    else {
        IMessage *msg = new ErrorMessage("08", "Cannot read input file.");
        logFile->addMessage(msg);
        error = true;
        return;
    }
}

bool Container :: isError() {
    return error;
}