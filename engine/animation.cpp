#include "animation.h"

void Animator::setup_animation(int fCount, Vector2 fSize, float fDur)
{
    _animation.frame_count = fCount;
    _animation.frame_sie = fSize;
    _animation.frame_duration = fDur;
    _animation.frame_duration_left = fDur;
    _animation.frame_current = 0;
};

void Animator::animation_update(Animation* animation) //todo: migrate to _animation instead of reference
{
    float dt = GetFrameTime();
    animation->frame_duration_left -= dt;

    if (animation->frame_duration_left <= 0)
    {
        animation->frame_duration_left = animation->frame_duration;
        animation->frame_current++;
        if (animation->frame_current > animation->frame_count-1)
        {
            animation->frame_current = 0;
        }
    }  
};

//! Only horizontal animations sprite-sheets
Rectangle Animator::get_animation_frame(Animation* animation)
{
    float x = (animation->frame_current % animation->frame_count) * animation->frame_sie.x;
    float y = (animation->frame_current / animation->frame_count) * animation->frame_sie.x;
    return (Rectangle) {
        .x = x,
        .y = y,
        .width = animation->frame_sie.x,
        .height = animation->frame_sie.y
    };
};