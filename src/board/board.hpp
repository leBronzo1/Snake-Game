# pragma once

#include <SFML/Graphics.hpp>

// Defines whether a square in the board has a fruit, snake, or nothing on it
enum class status : char {
    snaked,
    fruit,
    empty
};


class Board {
    private:
        status squares[300][300];
    public:
        // Construcor
        Board();

        // Deconstructor
        ~Board();

        void update();

        // Visualizing positions
        void render();
};