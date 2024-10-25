#include "levelStateManager.hpp"

levelState::levelState()
{
    DEBUG_LOG("Creating levelStateManager obj...");
    m_map = new map;
    m_monster = new monster;
    m_npc = new npc;
    m_window = new window;
    m_eventHandler = new eventHandler;
    m_hero = new hero;
}