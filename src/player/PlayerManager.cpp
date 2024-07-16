#include "PlayerManager.h"
#include "../Game.h"
#include "../ECS/Components.h"

void PlayerManager::init(Entity &playerEntity, int xpos, int ypos)
{
    playerEntity.addComponent<TransformComponent>(xpos - 32, ypos - 32);
    playerEntity.addComponent<SpriteComponent>("./assets/player.png");
}
