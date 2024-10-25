#pragma once
#include "loads/loadsManager.hpp"
#include "levelState/levelStateManager.hpp"
#include "assets/assetManager.hpp"
class game
{
public:
    game();
    void update();
    void run();

private:
    bool m_running;
    loadManager *m_loadManager;
    assetManager *m_assetManager;
    levelState *m_levelStateManager;
};