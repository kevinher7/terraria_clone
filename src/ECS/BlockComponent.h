#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "../Game.h"
#include <SDL3/SDL.h>
#include <string>

class BlockComponent : public Component
{
public:
    BlockComponent(int xpos, int ypos, int id)
        : transform{nullptr}, sprite{nullptr}, blockRect{static_cast<float>(xpos), static_cast<float>(ypos), 20.0f, 20.0f}, blockID{id}, spritePath{}
    {
        switch (blockID)
        {
        case 0:
            spritePath = "assets/water.png";
            break;
        case 1:
            spritePath = "assets/dirt.png";
            break;
        case 2:
            spritePath = "assets/grass.png";
            break;
        default:
            break;
        }
    }

    void init() override
    {
        entity->addComponent<TransformComponent>(static_cast<int>(blockRect.x), static_cast<int>(blockRect.y), static_cast<int>(blockRect.w), static_cast<int>(blockRect.h), 1);
        transform = &entity->getComponent<TransformComponent>();

        entity->addComponent<SpriteComponent>(spritePath.c_str());
        sprite = &entity->getComponent<SpriteComponent>();
    }

    TransformComponent *transform;
    SpriteComponent *sprite;

    SDL_FRect blockRect;
    int blockID;
    // char *spritePath; // warning de pasar de const char* a char*
    std::string spritePath;

private:
    BlockComponent(const BlockComponent &) = delete;
    BlockComponent &operator=(const BlockComponent &) = delete;
    BlockComponent(BlockComponent &&) = delete;
    BlockComponent &operator=(BlockComponent &&) = delete;
    ~BlockComponent() = default;
};
