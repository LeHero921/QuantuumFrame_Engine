#pragma once

class Object {
public:
    virtual ~Object() = default;

    virtual void Start(){};
    virtual void Update(float deltTime){};
    virtual void DrawSelf(){};
};