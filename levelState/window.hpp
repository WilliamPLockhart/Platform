#pragma once
#include "../global.hpp"

struct texts
{
    SDL_Surface *textSurface = nullptr;
    SDL_Rect rect;
    int posX, posY;
    SDL_Color color;
    std::string fontName;
};

class window
{
public:
    ~window();
    window();
    void renderAll();
    bool getWindowStatus() { return m_winOBJRunning; }
    void renderText();
    // void window::renderSprites();
    std::stack<texts> getTTFStack() { return m_TextTTF; }

private:
    bool m_winOBJRunning;
    SDL_Renderer *m_ren = nullptr;
    SDL_Window *m_win = nullptr;
    int m_windowHeight, m_windowWidth, m_windowX, m_windowY;
    std::stack<texts> m_TextTTF;
};