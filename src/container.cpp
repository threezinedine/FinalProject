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
    
    // Return and get error if command line is not valid
    if (!commandLineHandler->isValidCommand()){
        error = true;
        logFile = new LogFile("", "");
        logFile->addMessage(commandLineHandler->getMsg());
        return;
    }

    logFile = new LogFile(commandLineHandler->getInputFileName(),
                                        commandLineHandler->getOputputFileName());
    
    /*
        If input is .txt -> cannot use sorting mode.
    */
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
    /*
        Step 1: Read Data by IDataFile input and assign to Data object
        Step 2: run Sorting mode if user want to
        Step 3: Save Data by IDataFile ouput
    */
    if (input->canReadData()) {

        // asking if output file is exist
        if (output->isFileExist()) {
            if (!output->warningFileExit()) {
                error = true;
                IMessage *msg = new ErrorMessage("07", "Output file exists.");
                logFile->addMessage(msg);
                return;
            }
        }
        data = input->readData();

        // run sorting mode if user want to
        if (commandLineHandler->onSortingMode()){
            data->sort(commandLineHandler->getSortType(), commandLineHandler->getSortOrder());
        }

        // output receive Data object and save to output file
        output->getSaveString(data);
        output->save();
    }
    else {
        // if cannot read input file.
        IMessage *msg = new ErrorMessage("08", "Cannot read input file.");
        logFile->addMessage(msg);
        error = true;
        return;
    }
}

bool Container :: isError() {
    return error;
}