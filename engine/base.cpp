#include "base.h"

bool glContext;

bool Base::IsValidTexture(const Texture2D& texture) {
    return texture.id != 0; // 0 = ungültige Texture in raylib
};

bool Base::IsValidRect(const Rectangle& rect) {
    return rect.width != 0 && rect.height != 0;
};

bool Base::IsValidSprite(const Sprite& sprite) {
    return IsValidTexture(sprite.texture) &&
           IsValidRect(sprite.dest_rect) &&
           IsValidRect(sprite.source_rect);
};

bool Base::IsValidRenderStructure(const RenderStructure& rs) {
    return IsValidSprite(rs.sprite);
};

bool Base::valid_glCtx()
{
    return true;
};

Vector2 Base::Normalize(const Vector2& v)
{
    float length = sqrtf(v.x * v.x + v.y * v.y);
    if (length == 0.0f) return {0.0f, 0.0f};
    return {v.x / length, v.y / length};
};