#include "eventHandler.hpp"

eventHandler::eventHandler()
{
    DEBUG_LOG("Creating event handler obj...");
    m_event = new SDL_Event;
    m_eventHandlerRunning = true;
}

eventHandler::~eventHandler()
{
    DEBUG_LOG("Destroying event handler obj...");
    m_eventHandlerRunning = false;
}

void eventHandler::handleInputs()
{
    while (SDL_PollEvent(m_event) != 0)
    {
        // User requests quit
        if (m_event->type == SDL_QUIT)
        {
            inputQueue.push(INPUT_EXIT);
        }
    }
}