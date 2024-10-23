#pragma once
#include "global.hpp"

class game
{
public:
    game();
    void update();
    void run();

private:
    bool m_running;
};