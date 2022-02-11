#include <iostream>
#include <file_operations.h>
#include <string>
#include <vector>
#include <fstream>
#include <string_operators.h>


vector<string> readFile(string fileName) {
    // intialize vector of string to store data line by line.
    vector<string> result;          
    
    // define and open file with read mode
    fstream file;                   
    file.open(fileName, ios::in);

    string line;
    /*
        With each line of the file, push to the back of the result vector
    */
    while (!file.eof()) {
        getline(file, line);
        result.push_back(line);
    }

    // Close the file and return result
    file.close();
    return result;
}


void writeFile(string fileName, string writtenData) {
    //Intilize and open File in write mode
    fstream file;
    file.open(fileName, ios::out);

    // Write data and close file
    file << writtenData;
    file.close();
    return;
}

string getFileNameNoEx(string fileName){
    vector<string> vectStr = divideString(fileName, '.');
    vectStr.erase(vectStr.end()-1);
    return vectStr.back();
}