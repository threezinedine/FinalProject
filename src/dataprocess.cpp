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
    // LogFile *logFile = new LogFile("input.txt", "output.txt");

    Container container = Container(args, argv);
    if (!container.isError()) {
        container.transfer();
    }

    container.getLogFile()->save();
}