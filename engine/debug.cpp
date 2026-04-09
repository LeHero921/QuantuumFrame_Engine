#include "debug.h"
#include <iostream>

void Debug::log(const std::string& text)
{
    std::cout << "[DEBUG] " << text << std::endl;
};

void Debug::throwNotImplemented()
{
    std::cout << "[DEBUG] No Implementation Exeption!";
};