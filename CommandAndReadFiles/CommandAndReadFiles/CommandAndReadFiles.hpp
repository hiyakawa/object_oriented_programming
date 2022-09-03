//
//  CommandAndReadFiles.hpp
//  CommandAndReadFiles
//
//  Created by Laura Zhang on 2/18/21.
//

#ifndef CommandAndReadFiles_hpp
#define CommandAndReadFiles_hpp

#include <string>
#include <vector>

enum arg_opcode {
    NO_ARG_NAME_GIVEN = 1,
    TOO_MANY_FILENAMES = 3,
};

enum opcode {
    SUCCESS = 0,
    PARSE_SUCCESS = 0,
    NO_FILE_NAME_GIVEN = -1,
    FILE_OPEN_FAILED = -2,
};

int error_message(const std::string& program_name, std::string err_message, int err_type);

int parseFile(std::vector<std::string>& str_vec, const char* file_name);

bool isAllNum(std::string str);

bool isAllString(std::string str);

void printStringVector(std::vector<std::string>& str_vec);

void printIntVector(std::vector<int>& int_vec);

#endif /* CommandAndReadFiles_hpp */
