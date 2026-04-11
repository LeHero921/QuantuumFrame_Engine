#pragma once
#include <vector>
#include <memory>
#include "raylib.h"
#include "object.h"

class Application {
private:
    std::vector<std::unique_ptr<Object>> objects;

public:
    /// @brief Inits the application window
    /// @param width screen width
    /// @param height screen height
    /// @param title window title
    /// @param target_fps target FPS for the application (usually 60)
    /// @param background_color color for the background
    bool Init(int width, int height, const char* title, int target_fps, Color background_color);

    /// @brief Adds a object to the applications object list
    /// @param object the object data to add
    void AddObject(std::unique_ptr<Object> object);

    /// @brief Traps you into the matrix i guess
    void Run();

    /// @brief Exits the matrix i guess
    void Exit();
};