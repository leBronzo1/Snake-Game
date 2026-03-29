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

        // Boolean that denotes whether the snake is alive(Just a bool to send things into game over)
        bool alive;
    public:
        // Constructor
        Snake();

        // Update the position of the snake
        void updatePos();

        // Returns the snake to update board
        std::deque<sf::Vector2i> retVec() {return body;};

        // Boolean return that keeps track of status of snake
        bool retAlive() {return alive;}

        sf::Vector2i getHead() const;
};