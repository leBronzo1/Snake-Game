#include <iostream>
#include "game/game.hpp"

int main() {
    Game game;

    // Game loop
    while (game.isRunning()) {
        game.update();
        game.render();
    }

    return 0;
}