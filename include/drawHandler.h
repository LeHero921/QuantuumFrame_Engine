#pragma once
#include "base.h"
#include "entity.h"
#include "animation.h"

class DrawHandler {
public:
    void RenderEntity(const entityData& data);
    void RenderEntityAnimation(const entityData& data, Animator* a);
};