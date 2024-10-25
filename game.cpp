#include "game.hpp"

game::game()
{
    m_running = true;
    m_loadManager = new loadManager;
    m_assetManager = new assetManager;
    m_levelStateManager = new levelState;
}

void game::run()
{

    DEBUG_LOG("Game is running...");
    while (m_running)
    {
        // take input
        update();
        // render(inputs, updates)
    }
}

void game::update()
{
    m_running = false;
}
