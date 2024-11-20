#pragma once
#include "hero.hpp"
#include "map.hpp"
#include "monster.hpp"
#include "npc.hpp"
#include "window.hpp"
#include "eventHandler.hpp"

struct assetInfo
{
    std::string titleKey = "";
    std::string fileName = "";
    SDL_Surface *textSurface = nullptr;
    SDL_Texture *texture = nullptr;
    TTF_Font *font = nullptr;
    SDL_Rect *rect = nullptr;
    int *size = nullptr;
};

class assetManager;

class levelState
{
public:
    levelState(assetManager *m_assetManager);
    ~levelState();
    void render() { m_window->renderAll(); }
    void handleInputs() { m_eventHandler->handleInputs(); }
    bool getLevelStateStatus() { return m_levelStateStatus; }
    void updateMangaer(bool *exitflag);
    void requestAssets();

private:
    std::queue<assetInfo *> *m_loadAssetQueue;
    bool m_levelStateStatus;
    eventHandler *m_eventHandler;
    map *m_map;
    window *m_window;
    monster *m_monster;
    npc *m_npc;
    hero *m_hero;
    assetManager *m_assetManager;
};