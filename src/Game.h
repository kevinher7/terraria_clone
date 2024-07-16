#include <SDL3/SDL.h>

class Game
{
public:
    Game(const char *windowTitle, int width, int height);
    ~Game();

    void handleEvents();
    void update();
    void render();

    bool running() const { return m_isRunning; }

    int windowWidth;
    int windowHeight;
    inline static SDL_Renderer *gameRenderer{nullptr};
    static SDL_Event gameEvent;

private:
    SDL_Window *m_gameWindow;
    bool m_isRunning;

    Game() = delete;
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
    Game(Game &&) = delete;
    Game &operator=(Game &&) = delete;
};
