#pragma once
#include "raylib.h"

typedef struct Sprite
{
    Texture2D texture;
    Rectangle dest_rect;
    Rectangle source_rect;
} Sprite;

typedef struct RenderStructure
{
    Sprite sprite; // texture & dest_rect & source_rect
    Color tint;
} RenderStructure;