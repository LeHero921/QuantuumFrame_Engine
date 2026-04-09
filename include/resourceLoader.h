#pragma once
#include "base.h"
#include <iostream>

class ResourceLoader
{
public:
    static Texture2D& loadResource(const std::string& path);
    static void unloadResource(const std::string& path);
    static void unloadAll();

private:
    static std::unordered_map<std::string, Texture2D> loadedResources;
};