#pragma once
#include "hero.hpp"
#include "map.hpp"
#include "monster.hpp"
#include "npc.hpp"
#include "window.hpp"
#include "eventHandler.hpp"
class levelState
{
public:
    levelState();

private:
    eventHandler *m_eventHandler;
    map *m_map;
    window *m_window;
    monster *m_monster;
    npc *m_npc;
    hero *m_hero;
};