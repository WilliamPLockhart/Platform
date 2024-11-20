#include "loadsManager.hpp"

loadManager::loadManager()
{
    DEBUG_LOG("Creating loadManager obj...");
    m_mainMenu = new mainMenu;
    m_newGame = new newGame;
}

loadManager::~loadManager()
{
    DEBUG_LOG("Destroying loadManager obj...");
    if (m_mainMenu)
        delete m_mainMenu;

    if (m_newGame)
        delete m_newGame;
}