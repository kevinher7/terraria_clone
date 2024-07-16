#include "Game.h"
#include <iostream>

SDL_Event Game::gameEvent{};

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
    else
    {
        std::cerr << "Subsystems Initialization Failed\n";
    }
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

void Game::update() {}
void Game::render() {}

Game::~Game()
{
    SDL_DestroyWindow(m_gameWindow);
    SDL_DestroyRenderer(gameRenderer);
    SDL_Quit();
}
