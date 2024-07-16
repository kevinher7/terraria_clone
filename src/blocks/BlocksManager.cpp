#include "BlocksManager.h"
#include "../ECS/Components.h"

void BlockManager::placeLine(int xinit, int yinit, int id, int numBlocks)
{
    for (int b{0}; b < numBlocks; b++)
    {
        Entity &newBlock{Game::gameManager.addEntity()};
        newBlock.addComponent<BlockComponent>(xinit + 20 * b, yinit, id);
        Game::blocks.push_back(&newBlock);
    }
}
