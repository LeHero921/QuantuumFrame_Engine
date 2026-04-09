#include "input.h"
#include <raylib.h>

Vector2 Input::GetDirectionalInput() {
    return {
        (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * 1.0f,
        (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * -1.0f
    };
};