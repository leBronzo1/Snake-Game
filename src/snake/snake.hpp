#pragma once

#include <iostream>
#include <deque>

#include <SFML/Graphics.hpp>

// Handles what direction the snake is currently in
enum class Direction {
    Up,
    Down,
    Left,
    Right
};

// Handles Snake positions and movement
class Snake {
    private:
        // Then len of the snake
        int len;

        // Handles position and size of the snake
        std::deque<sf::Vector2i> body;

        // Current direction
        Direction cDirr;

        // Boolean that denotes whether the snake is growing
        bool growing = false;
    public:
        // Constructor
        Snake();

        // Update the position of the snake
        void updatePos();

        // Returns the snake to update board
        std::deque<sf::Vector2i> retVec() {return body;};

        // Gets head from body
        sf::Vector2i getHead() const {return body.front();}

        // Changes dirrection of snake
        void setDirection(Direction dir);

        // Returns whether the snake is growing or not
        void grow() {growing = true;}
};