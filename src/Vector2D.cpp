#include "Vector2D.h"

Vector2D &Vector2D::Zero()
{
    x = 0.0f;
    y = 0.0f;

    return *this;
}

Vector2D &Vector2D::Add(const Vector2D vector)
{
    this->x += vector.x;
    this->y += vector.y;

    return *this;
}
Vector2D &Vector2D::Subtract(const Vector2D vector)
{
    this->x -= vector.x;
    this->y -= vector.y;

    return *this;
}
Vector2D &Vector2D::Multiply(const Vector2D vector)
{
    this->x *= vector.x;
    this->y *= vector.y;

    return *this;
}
Vector2D &Vector2D::Divide(const Vector2D vector)
{
    this->x /= vector.x;
    this->y /= vector.y;

    return *this;
}

Vector2D operator+(Vector2D &v1, const Vector2D &v2)
{
    return v1.Add(v2);
}

Vector2D operator-(Vector2D &v1, const Vector2D &v2)
{
    return v1.Subtract(v2);
}

Vector2D operator*(Vector2D &v1, const Vector2D &v2)
{
    return v1.Multiply(v2);
}

Vector2D operator/(Vector2D &v1, const Vector2D &v2)
{
    return v1.Divide(v2);
}

Vector2D &Vector2D::operator+=(const Vector2D &vector)
{
    return this->Add(vector);
}

Vector2D &Vector2D::operator-=(const Vector2D &vector)
{
    return this->Subtract(vector);
}

Vector2D &Vector2D::operator*=(const Vector2D &vector)
{
    return this->Multiply(vector);
}

Vector2D &Vector2D::operator/=(const Vector2D &vector)
{
    return this->Divide(vector);
}

std::ostream &operator<<(std::ostream &outputStream, const Vector2D &vector)
{
    outputStream << "(" << vector.x << ", " << vector.y << ")";
    return outputStream;
}
