#include "physics.h"
#include "base.h"
#include "entity.h"
#include "debug.h"

// Each frame
void Physics::apply_gravity(PhysicsObj* pObj)
{
    // if (pObj->velocity.x <0.1f && pObj->velocity.x >-0.1f || pObj->velocity.y <0.1f && pObj->velocity.y >-0.1f) return;
    
    // Positiv
    if(pObj->velocity.x >= 0) {
        pObj->velocity.x += pObj->mass * GetFrameTime();
    }
    if(pObj->velocity.y >= 0) {
        pObj->velocity.y -= pObj->mass * GetFrameTime();
    }
    // Negative
    if(pObj->velocity.x <= 0) {
        pObj->velocity.x -= pObj->mass * GetFrameTime();
    }
    if(pObj->velocity.y <= 0) {
        pObj->velocity.y += pObj->mass * GetFrameTime();
    }
};

void Physics::apply_velocity(entityData* _data)
{
    _data->transform.position.x += _data->physicsObj.velocity.x * GetFrameTime();
    _data->transform.position.y += -_data->physicsObj.velocity.y * GetFrameTime();
    // Debug::log("phys debug:");
    // Debug::log(VToString(_data->transform.position));
};

void Physics::move(PhysicsObj* pObj)
{
    float speed = pObj->speed;
    pObj->velocity.x = pObj->direction.x * speed;
    pObj->velocity.y = pObj->direction.y * speed;

    // std::string a = "phys debug " + VToString(pObj->velocity);
    // Debug::log(a);
};