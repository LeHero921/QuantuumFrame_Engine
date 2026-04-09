#pragma once
#include <raylib.h>
#include <iostream>

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

typedef struct qTransform
{
    Vector2 position;
    float rotation;
} qTransform;

class Base {
public:
    bool IsValidTexture(const Texture2D& texture);
    bool IsValidRect(const Rectangle& rect);
    bool IsValidSprite(const Sprite& sprite);
    bool IsValidRenderStructure(const RenderStructure& rs);
    bool valid_glCtx();
    Vector2 Normalize(const Vector2& v);

    bool glContext;
};