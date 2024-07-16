#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "ECS.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
public:
    TransformComponent()
        : position{0.0f, 0.0f}, velocity{0.0f, 0.0f}, acceleration{0.0f, 0.3f}, height{64.0f}, width{64.0f}, scale{1.0f}, speed{6.0f} {}
    TransformComponent(int x_pos, int y_pos)
        : position{x_pos, y_pos}, velocity{0.0f, -4.0f}, acceleration{0.0f, 0.3f}, height{64.0f}, width{64.0f}, scale{1.0f}, speed{6.0f} {}
    TransformComponent(int x_pos, int y_pos, int w, int h, int sc)
        : position{x_pos, y_pos}, velocity{0.0f, 0.0f}, acceleration{0.0f, 0.3f}, height{static_cast<float>(h)}, width{static_cast<float>(w)}, scale{static_cast<float>(sc)}, speed{6.0f} {}
    TransformComponent(int sc)
        : position{0.0f, 0.0f}, velocity{0.0f, 0.0f}, acceleration{0.0f, 0.3f}, height{64.0f}, width{64.0f}, scale{static_cast<float>(sc)}, speed{6.0f} {}

    void update() override
    {

        position.x += velocity.x * speed;
        position.y += velocity.y * speed;

        if (velocity.y < 0)
        {
            velocity.y += acceleration.y;
        }

        if (position.y > 360 - 32)
        {
            velocity.y = 0;
        }
    }

    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;

    float height;
    float width;
    float scale;

    float speed;
};

#endif
