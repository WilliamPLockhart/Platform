#include "loadsManager.hpp"

loadManager::loadManager()
{
    DEBUG_LOG("Creating loadManager obj...");
    m_mainMenu = new mainMenu;
    m_newGame = new newGame;
}