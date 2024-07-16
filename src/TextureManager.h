#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL3/SDL.h> // no se pq pero no puede abrir desde ECS

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *imagePath);
    static void DrawTexture(SDL_Texture *texture, SDL_FRect srcRec, SDL_FRect destRec);
};

#endif
