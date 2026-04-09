#pragma once
#include <iostream>

class Debug{
public:
    static void log(const std::string& text);
    static void throwNotImplemented();
};