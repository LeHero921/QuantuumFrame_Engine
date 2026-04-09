#pragma once
#include "base.h"
#include "physics.h"

struct entityData
{
    qTransform transform;
    RenderStructure renderer;
    PhysicsObj physicsObj;
};

struct entityConfig
{
    std::string texturePath;
    Vector2 position;
    Vector2 size;
    Color tint = WHITE;
    float rotation = 0.0f;
    Vector2 velocity = {0, 0};
    float mass = 1.0f;
    float speed;
};


class Entity
{
public:
    Entity(const qTransform& t, const RenderStructure& r, const PhysicsObj& p);
    ~Entity();

    entityData _data;

    static Entity create_entity(const entityConfig& conf);
    void update_entity_transform();
    void load_entity_texture();
    void remove_entity();
};