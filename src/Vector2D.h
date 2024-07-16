#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D
{
public:
    Vector2D() : x{0.0f}, y{0.0f} {}
    Vector2D(float xInitial, float yInitial) : x{xInitial}, y{yInitial} {}
    Vector2D(int xInitial, int yInitial) : x{static_cast<float>(xInitial)}, y{static_cast<float>(yInitial)} {}

    Vector2D &Zero();

    Vector2D &Add(const Vector2D vec);
    Vector2D &Subtract(const Vector2D vec);
    Vector2D &Multiply(const Vector2D vec);
    Vector2D &Divide(const Vector2D vec);

    friend Vector2D operator+(Vector2D &v1, const Vector2D &v2);
    friend Vector2D operator-(Vector2D &v1, const Vector2D &v2);
    friend Vector2D operator*(Vector2D &v1, const Vector2D &v2);
    friend Vector2D operator/(Vector2D &v1, const Vector2D &v2);

    Vector2D &operator+=(const Vector2D &vector);
    Vector2D &operator-=(const Vector2D &vector);
    Vector2D &operator*=(const Vector2D &vector);
    Vector2D &operator/=(const Vector2D &vector);

    friend std::ostream &operator<<(std::ostream &outputStream, const Vector2D &vector);

    float x;
    float y;
};

#endif
