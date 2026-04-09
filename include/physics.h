#pragma once
#include "base.h"

struct entityData;

typedef struct PhysicsObj
{
    Vector2 velocity;
    float mass;
    Vector2 direction;
    float speed;
} PhysicsObj;

class Physics{
public:
    void apply_gravity(PhysicsObj* pObj);
    void static move(PhysicsObj* pObj);
    void apply_velocity(entityData* _data);
};