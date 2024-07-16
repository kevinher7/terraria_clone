#include "TextureManager.h"
#include "Game.h"
#include <SDL3_image/SDL_image.h>

SDL_Texture *TextureManager::LoadTexture(const char *imagePath)
{
    SDL_Surface *tmpSurface{IMG_Load(imagePath)};
    SDL_Texture *newTexture{SDL_CreateTextureFromSurface(Game::gameRenderer, tmpSurface)};
    SDL_DestroySurface(tmpSurface);

    return newTexture;
}

void TextureManager::DrawTexture(SDL_Texture *texture, SDL_FRect srcRec, SDL_FRect destRec)
{
    SDL_RenderTexture(Game::gameRenderer, texture, &srcRec, &destRec);
}
