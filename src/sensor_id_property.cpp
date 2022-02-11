#include <iostream>
#include <string>
#include <sensor_id_property.h>
#include <error_message.h>
#include <i_message.h>
#include <log_file.h>
#include <string_operators.h>
#include <sstream>
#include <data.h>


void SensorIDProperty :: setValueInt(int newValueInt) {
    // if sensor value <= 0 -> raise Error
    if (newValueInt <= 0) {
        empty = true;
        IMessage *msg = new ErrorMessage("03", 
                    "Sensor ID is less than zero in row " + to_string(Data::NumRow));
        logFile->addMessage(msg);
        return;
    }
    else {
        valueInt = newValueInt;
    }
    empty = false;
    updateValue();
    updateHexValue();
}

SensorIDProperty :: SensorIDProperty (int valueInt, LogFile *logFile) {
    this->logFile = logFile;
    setValueInt(valueInt);
}

SensorIDProperty :: SensorIDProperty (LogFile *logFile) {
    this->logFile = logFile;
}

string SensorIDProperty :: getPropertyName() {
    return propertyName;
}
