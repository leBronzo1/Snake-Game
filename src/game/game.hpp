#pragma once

#include "../board/board.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// Denotes what state the game is in
enum class GameState {
    Menu,
    inGame,
    GameOver
};


// Class that acts as the game engine
class Game {
    private:
        // Window
        sf::RenderWindow* window;

        // Controls what state the game is in
        GameState state;

        // Board - handles rendering for the board and updating the elements of the board
        Board b;

        // Font var
        sf::Font *font;

        // The title text
        sf::Text *titleText;

        // Text that pops up to denote text
        sf::Text *startText;

        // Text that pops up when game is over
        sf::Text *gameOverText;

        // Initialize variables
        void initVars();

        // Create Window for game
        void initWindow();

        // Initilizes fonts
        void initFonts();

        // Initilizes texts
        void initText();

        // Handle window/keyboard events
        void pollEvents();

        sf::Clock clock;
        float moveTimer = 0.f;
        float moveInterval = 0.15f; // move every 0.15 seconds
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