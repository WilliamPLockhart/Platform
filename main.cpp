#include "game.hpp"

int main(int argc, char *argv[])
{
    DEBUG_LOG("Game is starting...");
    game *gamestate = new game;
    gamestate->run();
    return STATUS_SUCCESS;
}
