#pragma once
#include "../global.hpp"

class eventHandler
{
public:
    enum inputs
    {
        INPUT_EXIT = 0
    };
    eventHandler();
    ~eventHandler();
    void handleInputs();
    bool getHandlerStatus() { return m_eventHandlerRunning; }

    std::queue<inputs> inputQueue;

private:
    bool m_eventHandlerRunning;
    SDL_Event *m_event = nullptr;
};