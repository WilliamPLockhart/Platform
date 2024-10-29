#include "game.hpp"

game::game()
{
    m_running = true;
    m_loadManager = new loadManager;
    m_assetManager = new assetManager;
    m_levelStateManager = new levelState;
    if (m_levelStateManager->getLevelStateStatus() == STATUS_ERROR)
        m_levelStateManager->~levelState();
}

void game::run()
{

    DEBUG_LOG("Game is running...");
    while (m_running)
    {
        // take input
        m_levelStateManager->handleInputs();
        update();
        m_levelStateManager->render();
    }
    DEBUG_LOG("End of run...");
}

void game::update()
{
    bool exitFlag = false;
    m_levelStateManager->updateMangaer(&exitFlag);
    if (exitFlag)
    {
        endGame();
    }
}

void game::endGame()
{
    if (m_loadManager)
    {
        delete m_loadManager;
    }
    if (m_assetManager)
    {
        delete m_assetManager;
    }
    if (m_levelStateManager)
    {
        delete m_levelStateManager;
    }
    m_running = false;
    DEBUG_LOG("All objects created in game deleted...");
}
