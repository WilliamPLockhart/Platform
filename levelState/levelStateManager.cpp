#include "levelStateManager.hpp"

levelState::levelState()
{
    DEBUG_LOG("Creating levelStateManager obj...");
    m_levelStateStatus = STATUS_SUCCESS;
    m_window = new window;
    if (m_window->getWindowStatus() == STATUS_ERROR)
        m_levelStateStatus = STATUS_ERROR;

    m_map = new map;
    m_monster = new monster;
    m_npc = new npc;
    m_eventHandler = new eventHandler;
    m_hero = new hero;
}

levelState::~levelState()
{
    if (m_window)
    {
        delete m_window;
    }

    if (m_map)
    {
        delete m_map;
    }

    if (m_monster)
    {
        delete m_monster;
    }

    if (m_npc)
    {
        delete m_npc;
    }

    if (m_eventHandler)
    {
        delete m_eventHandler;
    }

    if (m_hero)
    {
        delete m_hero;
    }
    DEBUG_LOG("All levelstate objects freed...");
}

void levelState::updateMangaer(bool *exitFlag)
{
    while (!m_eventHandler->inputQueue.empty())
    {
        eventHandler::inputs I = m_eventHandler->inputQueue.front();
        m_eventHandler->inputQueue.pop();
        switch (I)
        {
        case eventHandler::INPUT_EXIT:
            *exitFlag = true;

        default:
            break;
        }
    }
}