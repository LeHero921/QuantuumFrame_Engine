#include "drawHandler.h"

void DrawHandler::RenderEntity(const entityData& data)
{
    DrawTexturePro(
        data.renderer.sprite.texture,
        data.renderer.sprite.source_rect,
        data.renderer.sprite.dest_rect,
        {0,0},
        data.transform.rotation,
        data.renderer.tint
    );
};

void DrawHandler::RenderEntityAnimation(const entityData& data, Animator* a)
{
    DrawTexturePro(
        data.renderer.sprite.texture,
        a->get_animation_frame(&a->_animation),
        data.renderer.sprite.dest_rect,
        {0,0},
        data.transform.rotation,
        data.renderer.tint
    );
};