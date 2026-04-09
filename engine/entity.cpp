#include "base.h"
#include "entity.h"
#include "resourceLoader.h"
#include "debug.h"

std::string VToString(const Vector2& v) {
    return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ")";
};

Entity::Entity(const qTransform& t, const RenderStructure& r, const PhysicsObj& p)
{
    _data = {
        t,
        r,
        p
    };
};

Entity::~Entity()
{
    ;
};

Entity Entity::create_entity(const entityConfig& conf)
{
    Texture2D tex = ResourceLoader::loadResource(conf.texturePath);
    Sprite spr = {
        tex,
        {conf.position.x, conf.position.y, conf.size.x, conf.size.y},
        {0,0, (float)tex.width, (float)tex.height},
    };
    RenderStructure render = { spr, conf.tint };
    qTransform transform = { {0,0}, 0 };
    PhysicsObj pObj = { conf.velocity, conf.mass, {0,0}, conf.speed };

    return Entity(transform, render, pObj);
};

void Entity::update_entity_transform()
{
    _data.renderer.sprite.dest_rect.x = _data.transform.position.x;
    _data.renderer.sprite.dest_rect.y = _data.transform.position.y;

    // Vector2 a = {_data.renderer.sprite.dest_rect.x,_data.renderer.sprite.dest_rect.y};
    // Debug::log("Entity Deb:");
    // Debug::log(VToString(a));
};

void Entity::load_entity_texture()
{
    Debug::throwNotImplemented();
};

void Entity::remove_entity()
{
    Debug::throwNotImplemented();
};