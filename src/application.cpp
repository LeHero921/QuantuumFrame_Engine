#include "application.h"

Color bg_color;

bool Application::Init(int width, int height, const char* title, int target_fps, Color background_color) {
    InitWindow(width, height, title);
    SetTargetFPS(target_fps);
    bg_color = background_color;
    return true;
}

void Application::AddObject(std::unique_ptr<Object> object) {
    object->Start();
    objects.push_back(std::move(object));
}

void Application::Run() {
    while (WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        for (auto& object : objects) {
            object->Update(deltaTime);
        }

        BeginDrawing();
        ClearBackground(bg_color);
        for (auto& object : objects) {
            object->DrawSelf();
        }
        EndDrawing();
    }
}

void Application::Exit() {
    CloseWindow();
}