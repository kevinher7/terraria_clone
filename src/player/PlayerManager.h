#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "../ECS/ECS.h"

class TransformComponent;

class PlayerManager
{
public:
    PlayerManager(Entity &playerEntity)
        : player{playerEntity} {}
    ~PlayerManager() = default;

    void init(int xpos, int ypos);

    // bool detectBlockCollision();
    // void handleBlockCollision();

    Entity &player;
    static TransformComponent *transform;
};

#endif
