#ifndef COLLISION_H
#define COLLISION_H

#include <SDL3/SDL.h>

class ColliderComponent;
class TransformComponent;

class Collision
{
public:
    static bool AABB(const SDL_FRect &rectA, const SDL_FRect &rectB);
    static bool AABB(const ColliderComponent &colliderA, const ColliderComponent &colliderB);
    static bool detectOnGround(ColliderComponent &collider, TransformComponent &transform);
};

#endif
