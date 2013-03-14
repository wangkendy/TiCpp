#include "Generators.h"

const char* CharGen::source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
const int CharGen::len = std::strlen(source);
