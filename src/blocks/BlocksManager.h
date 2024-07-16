#ifndef BLOCKSMANAGER_H
#define BLOCKSMANAGER_H

class Entity;

class BlockManager
{
public:
    BlockManager() = default;
    ~BlockManager() = default;

    static void placeLine(int xinit, int yinit, int id, int numBlocks);
};

#endif
