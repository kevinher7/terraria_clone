#include "Game.h"
#include "ECS/Components.h"
#include "player/PlayerManager.h"
#include "blocks/BlocksManager.h"
#include <vector>

SDL_Event Game::gameEvent{};
Manager Game::gameManager{};

Entity &player{Game::gameManager.addEntity()};
PlayerManager playerManager{player};

std::vector<Entity *> Game::blocks;
BlockManager blockManager{};

Game::Game(const char *windowTitle, int width, int height)
    : windowWidth{width}, windowHeight{height}, m_gameWindow{nullptr}, m_isRunning{false}
{
    SDL_InitFlags initFlags{0};
    SDL_WindowFlags winFlags{0};

    if (SDL_InitSubSystem(initFlags) == 0)
    {
        m_gameWindow = SDL_CreateWindow(windowTitle, windowWidth, windowHeight, winFlags);
        gameRenderer = SDL_CreateRenderer(m_gameWindow, NULL);

        SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 1);
        m_isRunning = true;
    }
}

void Game::init()
{
    playerManager.init(windowWidth / 2, windowHeight / 2);
    blockManager.placeLine(0, windowHeight / 2 - 10 + 32, 2, 50);
}

void Game::handleEvents()
{
    SDL_PollEvent(&gameEvent);
    switch (gameEvent.type)
    {
    case SDL_EVENT_QUIT:
        m_isRunning = false;
        break;

    default:
        break;
    }
}

void Game::update()
{
    Game::gameManager.refresh();
    Game::gameManager.update();
}
void Game::render()
{
    SDL_RenderClear(gameRenderer);
    Game::gameManager.draw();
    SDL_RenderPresent(gameRenderer);
}

Game::~Game()
{
    SDL_DestroyWindow(m_gameWindow);
    SDL_DestroyRenderer(gameRenderer);
    SDL_Quit();
}
