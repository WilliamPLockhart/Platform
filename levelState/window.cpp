#include "window.hpp"

window::window()
{
    DEBUG_LOG("Creating window obj...");
    // initializes
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        DEBUG_LOG("SDL could not initialize! SDL_Error:");
        DEBUG_LOG(SDL_GetError());
        m_winOBJRunning = STATUS_ERROR;
        return;
    }

    // creates the window
    m_windowWidth = 1280;
    m_windowHeight = 720;
    m_win = SDL_CreateWindow("Hello SDLWorld", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowWidth, m_windowHeight, SDL_WINDOW_SHOWN);
    if (m_win == nullptr)
    {
        DEBUG_LOG("Error Creating m_win...");
        SDL_Quit();
        m_winOBJRunning = STATUS_ERROR;
        return;
    }
    SDL_GetWindowPosition(m_win, &m_windowX, &m_windowY);

    // creates render
    m_ren = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED);
    if (m_ren == nullptr)
    {
        SDL_DestroyWindow(m_win);
        SDL_Quit();
        m_winOBJRunning = STATUS_ERROR;
        return;
    }
    m_winOBJRunning = STATUS_SUCCESS;
}

window::~window()
{
    DEBUG_LOG("Destroying window obj...");
    if (m_ren)
        SDL_DestroyRenderer(m_ren);
    if (m_win)
        SDL_DestroyWindow(m_win);
    SDL_Quit();
    m_winOBJRunning = STATUS_SUCCESS;
}

void window::renderAll()
{
    SDL_SetRenderDrawColor(m_ren, 0, 0, 255, 255);
    SDL_RenderClear(m_ren);
    SDL_RenderPresent(m_ren);
}