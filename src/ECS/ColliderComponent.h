#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "ECS.h"
#include "TransformComponent.h"
#include "./MovementComponents/JumpComponent.h"
#include "../Collision.h"
#include "../Game.h"

class ColliderComponent : public Component
{
public:
    ColliderComponent() = delete;
    ColliderComponent(std::string name)
        : transform{nullptr}, colliderBox{0.0f, 0.0f, 0.0f, 0.0f}, tagName{name}, isBlock{false} {}

    void init() override
    {
        if (!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }

        transform = &entity->getComponent<TransformComponent>();

        colliderBox.x = transform->position.x;
        colliderBox.y = transform->position.y;
    }

    void update() override
    {
        colliderBox.x = transform->position.x;
        colliderBox.y = transform->position.y;
        colliderBox.w = transform->width * transform->scale;
        colliderBox.h = transform->height * transform->scale;

        if (!isBlock)
        {
            Collision::detectOnGround(*this, *transform);
        }
    }

    TransformComponent *transform;
    SDL_FRect colliderBox;
    std::string tagName;
    bool isBlock;

private:
    ColliderComponent(const ColliderComponent &) = delete;
    ColliderComponent &operator=(const ColliderComponent &) = delete;
    ColliderComponent(ColliderComponent &&) = delete;
    ColliderComponent &operator=(ColliderComponent &&) = delete;
    ~ColliderComponent() = default;
};

#endif
