#ifndef GRAVITYCOMPONENT_H
#define GRAVITYCOMPONENT_H

#include "ECS.h"
#include "TransformComponent.h"
#include "ColliderComponent.h"

class GravityComponent : public Component
{
public:
    GravityComponent()
        : gravityAcceleration{0.2f}, transformer{nullptr}, collider{nullptr} {}
    ~GravityComponent() {}

    void init() override
    {
        transformer = &entity->getComponent<TransformComponent>();
        collider = &entity->getComponent<ColliderComponent>();
    }

    void update() override
    {
        if (!transformer->onGround)
        {
            transformer->velocity.y += gravityAcceleration;
        }
    }

    float gravityAcceleration;
    TransformComponent *transformer;
    ColliderComponent *collider;

private:
    GravityComponent(const GravityComponent &) = delete;
    GravityComponent &operator=(const GravityComponent &) = delete;
    GravityComponent(GravityComponent &&) = delete;
    GravityComponent &operator=(GravityComponent &&) = delete;
};

#endif
