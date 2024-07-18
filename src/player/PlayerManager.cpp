#include "PlayerManager.h"
#include "../Game.h"
#include "../Collision.h"
#include "../ECS/Components.h"
#include "../blocks/BlocksManager.h"
#include <iostream>

TransformComponent *PlayerManager::transform{};

void PlayerManager::init(int xpos, int ypos)
{
    player.addComponent<TransformComponent>(xpos - 32, ypos - 50);
    transform = &player.getComponent<TransformComponent>();

    player.addComponent<SpriteComponent>("./assets/player.png");
    player.addComponent<ColliderComponent>("player");
    player.addComponent<KeyboardController>();
    player.addComponent<GravityComponent>();
    player.addComponent<JumpComponent>();
}

// bool PlayerManager::detectBlockCollision()
// {
//     // for (auto blockCollider : BlockManager::blockColliders)
//     // {
//     //     if (Collision::AABB(player.getComponent<ColliderComponent>(), *blockCollider))
//     //     {
//     //         transform->velocity.y = 0;
//     //         transform->position.y = blockCollider.position.y + transform->height;
//     //         return true;
//     //     }
//     // }

//     // return false;
// }

// void PlayerManager::handleBlockCollision()
// {
//     if (detectBlockCollision() && transform->velocity.y != 0)
//     {
//         std::cerr << "detected collision, v!=0\n";
//         transform->velocity.y = 0;
//         // player.getComponent<TransformComponent>().velocity.y = 0;
//     }
// }
