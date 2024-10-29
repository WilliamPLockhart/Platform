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
    ~levelState();
    void render() { m_window->renderAll(); }
    void handleInputs() { m_eventHandler->handleInputs(); }
    bool getLevelStateStatus() { return m_levelStateStatus; }
    void updateMangaer(bool *exitflag);

private:
    bool m_levelStateStatus;
    eventHandler *m_eventHandler;
    map *m_map;
    window *m_window;
    monster *m_monster;
    npc *m_npc;
    hero *m_hero;
};