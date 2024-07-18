#ifndef BLOCKSMANAGER_H
#define BLOCKSMANAGER_H

#include <vector>

class Entity;
class ColliderComponent;

class BlockManager
{
public:
    BlockManager() = default;
    ~BlockManager() = default;

    static void placeLine(int xinit, int yinit, int id, int numBlocks);

    static std::vector<ColliderComponent *> blockColliders;
};

#endif
