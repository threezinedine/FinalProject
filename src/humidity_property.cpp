#include <iostream>
#include <humidity_property.h>
#include <string_operators.h>
#include <i_message.h>
#include <error_message.h>
#include <sstream>
#include <log_file.h>
#include <data.h>


void HumidityProperty :: setValueInt(int newValueInt) {
    // if humidity not in range (40, 95) -> raise Error
    if (newValueInt < 40 || newValueInt > 95) {
        empty = true;
        IMessage *msg = new ErrorMessage("04", 
                    "Humidity Property is not in range (40, 95) in row " 
                        + to_string(Data::NumRow));
        logFile->addMessage(msg);
        return;
    }
    valueInt = newValueInt;
    empty = false;
    updateValue();
    updateHexValue();
}

HumidityProperty :: HumidityProperty (LogFile *logFile) {
    this->logFile = logFile;
}

HumidityProperty :: HumidityProperty (int valueInt, LogFile *logFile) {
    this->logFile = logFile;
    setValueInt(valueInt);
}

string HumidityProperty :: getPropertyName() {
    return propertyName;
}