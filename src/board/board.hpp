#pragma once

#include "../snake/snake.hpp"
#include <SFML/Graphics.hpp>
#include <random>

// Defines whether a square in the board has a fruit, snake, or nothing on it
enum class square : char {
    snaked,
    fruit,
    empty
};


// Handles the entirety of the board functionaltiy including rendering
class Board {
    private:
        // Grid Size will not change
        static const int GRID_SIZE = 30;

        // Cell Size will not change
        static const int CELL_SIZE = 20;

        // Grid - handles where eveything is on grid so its easy to render
        square grid[GRID_SIZE][GRID_SIZE];

        // Snake - its positions and elements
        Snake snake;

        // Vector to keep track of one 
        sf::Vector2i fruitPos;

        // Random number generation elements 
        std::mt19937 gen; 
        std::uniform_int_distribution<int> distr;
    public:
        // Constructor — set grid size, cell size, spawn first food
        Board();

        // Spawn food in a random empty cell
        void spawnFood();

        // Check if a given position is food
        bool isFood(sf::Vector2i pos);

        // Check if a position is out of bounds (wall collision)
        bool isOutOfBounds(sf::Vector2i pos);

        // Draw the grid and food
        void render(sf::RenderWindow& window);
};