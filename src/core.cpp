#include "core.h"
#include "renderingData.h"

bool glContext;

bool Core::IsValidTexture(const Texture2D& texture) {
    return texture.id != 0; // 0 = invalid texture in raylib
};

bool Core::IsValidRect(const Rectangle& rect) {
    return rect.width != 0 && rect.height != 0;
};

bool Core::IsValidSprite(const Sprite& sprite) {
    return IsValidTexture(sprite.texture) &&
           IsValidRect(sprite.dest_rect) &&
           IsValidRect(sprite.source_rect);
};

bool Core::IsValidRenderStructure(const RenderStructure& rs) {
    return IsValidSprite(rs.sprite);
};

bool Core::valid_glCtx()
{
    return true;
};

Vector2 Core::Normalize(const Vector2& v)
{
    float length = sqrtf(v.x * v.x + v.y * v.y);
    if (length == 0.0f) return {0.0f, 0.0f};
    return {v.x / length, v.y / length};
};