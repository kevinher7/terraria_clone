#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "../ECS/ECS.h"

class PlayerManager
{
public:
    PlayerManager(Entity &playerEntity)
        : player{playerEntity} {}
    ~PlayerManager() = default;

    void init(int xpos, int ypos);

    Entity &player;
};

#endif
