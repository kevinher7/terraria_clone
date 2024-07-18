#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include "TransformComponent.h"
#include "./MovementComponents/JumpComponent.h"
#include "../Game.h"

class KeyboardController : public Component
{
public:
    KeyboardController() : transform{nullptr} {}
    KeyboardController(const KeyboardController &) = delete;
    KeyboardController &operator=(const KeyboardController &) = delete;
    KeyboardController(KeyboardController &&) = delete;
    KeyboardController &operator=(KeyboardController &&) = delete;
    ~KeyboardController() = default;

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override
    {
        if (Game::gameEvent.type == SDL_EVENT_KEY_DOWN)
        {
            switch (Game::gameEvent.key.keysym.sym)
            {
            case SDLK_w:
                entity->getComponent<JumpComponent>().startedJump = true;
                entity->getComponent<JumpComponent>().update();
                break;
            case SDLK_a:
                transform->velocity.x = -1.0f;
                break;
            case SDLK_s:
                // transform->velocity.y = 1.0f;
                break;
            case SDLK_d:
                transform->velocity.x = 1.0f;
                break;

            default:
                break;
            }
        }

        if (Game::gameEvent.type == SDL_EVENT_KEY_UP)
        {
            switch (Game::gameEvent.key.keysym.sym)
            {
            case SDLK_w:
                // transform->velocity.y = 0;
                break;
            case SDLK_a:
                transform->velocity.x = 0;
                break;
            case SDLK_s:
                // transform->velocity.y = 0;
                break;
            case SDLK_d:
                transform->velocity.x = 0;
                break;

            default:
                break;
            }
        }
    }

    TransformComponent *transform;
};

#endif
