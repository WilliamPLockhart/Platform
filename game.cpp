#include "game.hpp"

game::game()
{
    m_running = true;
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
}
