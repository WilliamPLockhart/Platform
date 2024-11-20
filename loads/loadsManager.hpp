#pragma once
#include "mainMenu.hpp"
#include "newGame.hpp"

class loadManager
{
public:
    loadManager();
    ~loadManager();

private:
    mainMenu *m_mainMenu;
    newGame *m_newGame;
};