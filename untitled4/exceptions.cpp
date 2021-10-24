#include "exceptions.h"
#include <iostream>

void Exceptions::WrongArguments() {
    std::cerr << "The program expects 4 arguments\n"
                 "Example:\n"
                 "command -f input.txt output.txt\n";
}

void Exceptions::WrongMode() {
    std::cerr << "invalid mod specified\n"
                 "Expected:\n"
                 "1) command -f input.txt output.txt\n"
                 "2) command -n number output.txt\n";
}