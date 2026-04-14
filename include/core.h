#pragma once
#include <iostream>
#include "raylib.h"
#include "libQuantuum.h"

typedef struct qTransform
{
    Vector2 position;
    float rotation;
} qTransform;

class Core {
public:
    bool IsValidTexture(const Texture2D& texture);
    bool IsValidRect(const Rectangle& rect);
    bool IsValidSprite(const Sprite& sprite);
    bool IsValidRenderStructure(const RenderStructure& rs);
    bool valid_glCtx();
    Vector2 Normalize(const Vector2& v);

    bool glContext;
};