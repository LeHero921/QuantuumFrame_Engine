#pragma once
#include "libQuantuum.h"

class DrawHandler {
public:
    void RenderEntity(const entityData& data);
    void RenderEntityAnimation(const entityData& data, Animator* a);
};