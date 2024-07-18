#ifndef JUMPCOMPONENT_H
#define JUMPCOMPONENT_H

#include "../ECS.h"
#include "../TransformComponent.h"
#include "../ColliderComponent.h"
#include "../../blocks/BlocksManager.h"
#include "../../Collision.h"
#include <iostream>

class JumpComponent : public Component
{
public:
    JumpComponent()
        : transform{nullptr}, collider{nullptr}, startedJump{false} {}

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        collider = &entity->getComponent<ColliderComponent>();

        update();
    }

    void update() override
    {
        if (transform->onGround && startedJump)
        {
            transform->onGround = false;
            transform->velocity.y = -3.0f;
            startedJump = false;
        }
    }

    TransformComponent *transform;
    ColliderComponent *collider;
    bool startedJump;

private:
    JumpComponent(const JumpComponent &) = delete;
    JumpComponent &operator=(const JumpComponent &) = delete;
    JumpComponent(JumpComponent &&) = delete;
    JumpComponent &operator=(JumpComponent &&) = delete;
    ~JumpComponent() = default;
};

#endif
