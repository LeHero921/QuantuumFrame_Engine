#include "base.h"
#include "resourceLoader.h"
#include "debug.h"
#include <iostream>

std::unordered_map<std::string, Texture2D> ResourceLoader::loadedResources;

Texture2D& ResourceLoader::loadResource(const std::string& path)
{
    auto it = loadedResources.find(path);
    if (it != loadedResources.end())
    {
        return it->second;
    }
    loadedResources[path] = LoadTexture(path.c_str());
    Debug::log("[Resources] Loaded Resource");
    return loadedResources[path];
};

void ResourceLoader::unloadResource(const std::string& path)
{
    auto it = loadedResources.find(path);
    if (it != loadedResources.end())
    {
        UnloadTexture(it->second);
        loadedResources.erase(it);
        Debug::log("[Resources] Unloaded and Erased one item");
    }
};

void ResourceLoader::unloadAll()
{
    for (auto& [path, texture] : loadedResources)
    {
        UnloadTexture(texture);
    }
    loadedResources.clear();
    Debug::log("[Resources] Unloaded all!");
};