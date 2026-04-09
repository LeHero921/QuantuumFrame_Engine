#pragma once
#include <raylib.h>

typedef struct Animation
{
    //! Mandatory
    int frame_count;                    // frame count lol
    Vector2 frame_sie;                  // x, y of all frames
    float frame_duration;               // time for each frame on screen
    
    //* runtime
    int frame_current;                  // index of the current frame
    float frame_duration_left;          // time left for current frame (dur_left->fr_dur)
} Animation;

class Animator
{
public:
    Animation _animation;
    void setup_animation(int fCount, Vector2 fSize, float fDur);
    void animation_update(Animation* animation);
    Rectangle get_animation_frame(Animation* animation);
};