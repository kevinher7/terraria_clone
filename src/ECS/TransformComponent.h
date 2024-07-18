#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "ECS.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
public:
    TransformComponent()
        : position{0.0f, 0.0f}, velocity{0.0f, 0.0f}, height{60.0f}, width{40.0f}, scale{1.0f}, speed{6.0f}, onGround{false} {}
    TransformComponent(int x_pos, int y_pos)
        : position{x_pos, y_pos}, velocity{0.0f, 0.0f}, height{60.0f}, width{40.0f}, scale{1.0f}, speed{6.0f}, onGround{false} {}
    TransformComponent(int x_pos, int y_pos, int w, int h, int sc)
        : position{x_pos, y_pos}, velocity{0.0f, 0.0f}, height{static_cast<float>(h)}, width{static_cast<float>(w)}, scale{static_cast<float>(sc)}, speed{6.0f}, onGround{false} {}
    TransformComponent(int sc)
        : position{0.0f, 0.0f}, velocity{0.0f, 0.0f}, height{60.0f}, width{40.0f}, scale{static_cast<float>(sc)}, speed{6.0f}, onGround{false} {}

    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

    Vector2D position;
    Vector2D velocity;

    float height;
    float width;
    float scale;

    float speed;

    bool onGround;
};

#endif
