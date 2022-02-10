#include <iostream>
// #include <container.h>
#include <log_file.h>
#include <i_message.h>
#include <error_message.h>
#include <warning_message.h>
#include <i_message.h>
#include <sensor_id_property.h>
#include <string_operators.h>
#include <vector>
#include <data_row.h>
#include <data.h>
#include <sensor_data_file.h>
#include <binary_packet_file.h>
#include <command_line_handlder.h>
#include <container.h>
#include <temperature_property.h>
#include <time.h>
#include <ctime>
#include <time_operation.h>
#include <my_time.h>
#include <chrono>
#include <time_property.h>

using namespace std;


int main(int args, char* argv[]) {
    // Container mainContainer = Container(args, argv);
    // mainContainer.transfer();
    // mainContainer.getLogFile().save();
    LogFile *logFile = new LogFile("input.txt", "output.txt");

    // IMessage *msg1 = new ErrorMessage("01", "Input file cannot be read.");
    // IMessage *msg2 = new WarningMessage("02", "The output file exists.");
    // logFile.addMessage(msg1);
    // logFile.addMessage(msg2);
    // logFile.save();
    // IProperty *sensorId = new SensorIDProperty(194, logFile);
    // cout << "Hex Value: " << sensorId->getHexValue() << endl;
    // cout << "Value: " << sensorId->getValue() << endl;
    // cout << "Num Byte: " << sensorId->getNumByte() << endl;
    // cout << "Property Name: "<< sensorId->getPropertyName() << endl;

    // DataRow *dataRow = new DataRow("03,45", logFile);
    // DataRow *dataRow2 = new DataRow("04,56", logFile);
    // // cout << "Header Line: " << dataRow.getHeaderLine() << endl;
    // // cout << "Csv Line: " << dataRow.getSaveDataCSV() << endl;
    // // cout << "Txt line: " << dataRow.getSaveDataTXT() << endl;
    
    // DataRow *dataRow = new DataRow("00 0C 03 2D C4 FF", logFile);
    // DataRow *dataRow2 = new DataRow("00 0C 04 38 B8 FF", logFile);
    // // cout << "Header Line: " << dataRow->getHeaderLine() << endl;
    // // cout << "CSV Line:" << dataRow->getSaveDataCSV() << endl;
    // // cout << "CSV Line:" << dataRow2->getSaveDataCSV();

    // Data *data = new Data(logFile);
    // data->appendDataRow(dataRow);
    // data->appendDataRow(dataRow2);
    // cout << data->getSaveDataTXT() << endl;
    // cout << data->getSaveDataCSV();
    // CommandLineHandler *commandLineHandler = new CommandLineHandler(args, argv, logFile);
    // IDataFile *input = new SensorDataFile(commandLineHandler->getInputFileName(), logFile);
    // Data* data = input->readData();
    // IDataFile *output = new BinaryPacketFile(commandLineHandler->getOputputFileName(), logFile);
    // output->getSaveString(data);
    // output->save();
    Container container = Container(args, argv);
    container.transfer();
    container.getLogFile()->save();
    
    // IProperty* temperature = new TemperatureProperty(logFile);
    // temperature->setHexValue("41 99 5c 29");
    // cout << temperature->getHexValue();
    // cout << endl << "Value: " << temperature->getValue();

    // MyTime* time = new MyTime("2020-12-31 17:00:00");
    // // MyTime* time = new MyTime("2020-07-23 9:52:36");

    // cout << time->getFullTimeString();
    // cout << endl << time->getUnixLongNumber();

    // MyTime* time2 = new MyTime(1609408800);
    // cout << endl << time2->getFullTimeString();
    // cout << endl << time2->getUnixLongNumber();
    // cout << "Ok" << endl;
    // IProperty* time = new TimeProperty(logFile);
    // cout << "ok" << endl;
    // time->setValue("2020-12-31 17:00:00");
    // cout << time->getHexValue();
}