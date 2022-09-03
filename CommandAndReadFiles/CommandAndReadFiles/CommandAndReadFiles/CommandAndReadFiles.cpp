//
//  CommandAndReadFiles.cpp
//  CommandAndReadFiles
//
//  Created by Laura Zhang on 2/18/21.
//

#include "CommandAndReadFiles.hpp"

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;

// print an error message indicating the problem and return the enumeration label
int error_message(const string& program_name, string err_message, int err_type) {
    cout << "Usage: " << program_name << endl;
    cout << err_message << endl;
    
    return err_type;
}

// parsing an input file containing text strings and different forms of whitespace
int parseFile(vector<string>& str_vec, const char* file_name) {
    if (access(file_name, 0) != -1) {
        ifstream inputFile(file_name);
        string str;
        string word;

        if (! inputFile.is_open()) {
            return FILE_OPEN_FAILED;
        }

        while (getline(inputFile, str)) {
            stringstream str_stream(str);
            // each time a non-empty string is extracted, push it back into the vector
            while (str_stream >> word) {
                str_vec.push_back(word);
            }
        }
        
        inputFile.close();

        return SUCCESS;
    }
    
    return NO_FILE_NAME_GIVEN;
}

bool isAllNum(string str) {
    for (int i = 0; i < str.size(); i++) {
        int cur_char = (int)str[i];
        
        if (cur_char < 48 || cur_char > 57){
            return false;
        }
    }
    
    return true;
}

bool isAllString(string str) {
    for (int i = 0; i < str.size(); i++) {
        int cur_char = (int)str[i];
        
        if (cur_char > 47 && cur_char < 58) {
            return false;
        }
    }
    
    return true;
}

void printStringVector(vector<string>& str_vec) {
    for (string cur_str : str_vec) {
        cout << cur_str <<endl;
    }
}

void printIntVector(vector<int>& int_vec) {
    for (int cur_str : int_vec) {
        cout << cur_str <<endl;
    }
}
