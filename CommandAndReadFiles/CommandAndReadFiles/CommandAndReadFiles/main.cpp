//
//  main.cpp
//  CommandAndReadFiles
//
//  Created by Laura Zhang on 2/18/21.
//

#include "CommandAndReadFiles.hpp"

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<string> str_vec;
    vector<int> int_vec;
    string err_message = "";

    // check if argc == 2 (exactly one argument has been passed)
    if (argc == NO_ARG_NAME_GIVEN) {
        // call the usage message function
        err_message = "No arguments entered!";
        return error_message(argv[0], err_message, NO_ARG_NAME_GIVEN);
    }
    
    else if (argc >= TOO_MANY_FILENAMES) {
        // call the usage message function
        err_message = "Too many arguments entered!";
        return error_message(argv[0], err_message, TOO_MANY_FILENAMES);
    }

    //parsing the input file
    const char* file_name = argv[1];

    //if the file fails to open
    switch (parseFile(str_vec, file_name)) {
        case NO_FILE_NAME_GIVEN:
            // call the usage message function
            err_message = "This file does not exist!";
            return error_message(argv[0], err_message, NO_FILE_NAME_GIVEN);
            
        case FILE_OPEN_FAILED:
            err_message = "File open failed!";
            return error_message(argv[0], err_message, FILE_OPEN_FAILED);
            
        case SUCCESS:
            //check if it is an integer
            for (vector<string>::const_iterator iter = str_vec.begin(); iter != str_vec.end(); iter++) {
                if (isAllNum(* iter)) {
                    int num;
                    stringstream str_stream;
                    str_stream << * iter;
                    str_stream >> num;
                    int_vec.push_back(num);
                }
            }
            
            //print the string which contains non-digit characters to the standard output stream
            printStringVector(str_vec);
            printIntVector(int_vec);

            break;
    }
    
    system("PAUSE");

    return SUCCESS;
}
