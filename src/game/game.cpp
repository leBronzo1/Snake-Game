#include "game.hpp"

void Game::initVars() {
    this->window = nullptr;
    this->font = nullptr;
    this->titleText = nullptr;
    this->startText = nullptr;
    this->gameOverText = nullptr;
    this->state = GameState::Menu;
}

void Game::initFonts() {
    this->font = new sf::Font();
    if (!this->font->openFromFile("assets/font.ttf")) {
        delete this->font;
        this->font = nullptr;
        throw std::runtime_error("Failed to load font: assets/font.ttf");
    }
}

void Game::initText() {
    this->titleText = new sf::Text(*this->font);
    this->titleText->setString("SNAKE");
    this->titleText->setCharacterSize(60);
    this->titleText->setFillColor(sf::Color::Green);
    // Center it
    sf::FloatRect bounds = this->titleText->getLocalBounds();
    this->titleText->setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f});
    this->titleText->setPosition({300.f, 200.f}); // center of 600x600 window

    this->startText = new sf::Text(*this->font);
    this->startText->setString("Press Enter to Play");
    this->startText->setCharacterSize(24);
    this->startText->setFillColor(sf::Color::White);
    // Center it
    sf::FloatRect startBounds = this->startText->getLocalBounds();
    this->startText->setOrigin({startBounds.size.x / 2.f, startBounds.size.y / 2.f});
    this->startText->setPosition({300.f, 300.f});
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode({600, 600}), "Snake Game", sf::Style::Titlebar | sf::Style::Close);
}


// Finish menu from this point downwards
void Game::pollEvents() {
    while (const auto event = this->window->pollEvent()) {
        if (event->is<sf::Event::Closed>())
            this->window->close();

        if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
            switch (this->state) {
                case GameState::Menu:
                    if (key->code == sf::Keyboard::Key::Enter)
                        this->state = GameState::inGame;
                    break;
                case GameState::inGame:
                    if (key->code == sf::Keyboard::Key::Escape)
                        this->state = GameState::Menu;
                    break;
                case GameState::GameOver:
                    if (key->code == sf::Keyboard::Key::Enter)
                        this->state = GameState::inGame;
                    if (key->code == sf::Keyboard::Key::Escape)
                        this->state = GameState::Menu;
                    break;
            }
        }
    }
}

void Game::update() {
    this->pollEvents();

    switch (this->state) {
        case GameState::Menu:
            // nothing to update on menu
            break;
        case GameState::inGame:
            // snake.update(), board.update() etc
            break;
        case GameState::GameOver:
            // nothing to update on game over
            break;
    }
}

void Game::render() {
    this->window->clear(sf::Color::Black);

    switch (this->state) {
        case GameState::Menu:
            this->window->draw(*this->titleText);
            this->window->draw(*this->startText);
            break;
        case GameState::inGame:
            this->b.render(*this->window);
            break;
        case GameState::GameOver:
            this->window->draw(*this->gameOverText);
            break;
    }

    this->window->display();
}

Game::Game() {
    this->initVars();
    this->initWindow();
    this->initFonts();
    this->initText();
}

Game::~Game() {
    delete this->window;
    delete this->font;
    delete this->titleText;
    delete this->startText;
    delete this->gameOverText;
}
