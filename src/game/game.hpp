#pragma once

#include "../board/board.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


// Class that acts as the game engine
class Game {
    private:
        // Window
        sf::RenderWindow* window;

        // Board - handles rendering for the board and updating the elements of the board
        Board b;

        // Initialize variables
        void initVars();

        // Create Window for game
        void initWindow();

        // Handle window/keyboard events
        void pollEvents();
    public:
        // Constructor
        Game();

        // Destructor
        ~Game();

        // Handles game logic each frame (movement, collisions, score)
        void update();

        // Draws all game objects to the screen each frame
        void render();

        // Check if game is running
        bool isRunning() const { return this->window->isOpen(); }
};