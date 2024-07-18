#include "PlayerManager.h"
#include "../ECS/Components.h"

void PlayerManager::init(int xpos, int ypos)
{
    player.addComponent<TransformComponent>(xpos - 32, ypos - 50);
    player.addComponent<SpriteComponent>("./assets/player.png");
    player.addComponent<ColliderComponent>("player");
    player.addComponent<KeyboardController>();
    player.addComponent<GravityComponent>();
    player.addComponent<JumpComponent>();
}
