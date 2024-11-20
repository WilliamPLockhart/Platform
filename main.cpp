#include "game.hpp"
// to see file tree
// tree -I 'build|CMakeFiles|CMakeCache.txt|cmake_install.cmake|CPackConfig.cmake|CPackSourceConfig.cmake'
int main(int argc, char *argv[])
{
    DEBUG_LOG("Game is starting...");
    game *gamestate = new game;
    gamestate->run();
    return STATUS_SUCCESS;
}
