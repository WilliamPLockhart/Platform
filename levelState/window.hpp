#pragma once
#include "../global.hpp"

class window
{
public:
    ~window();
    window();
    void renderAll();
    bool getWindowStatus() { return m_winOBJRunning; }

private:
    bool m_winOBJRunning;
    SDL_Renderer *m_ren = nullptr;
    SDL_Window *m_win = nullptr;
    int m_windowHeight, m_windowWidth, m_windowX, m_windowY;
};