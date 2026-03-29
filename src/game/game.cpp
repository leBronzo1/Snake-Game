#include "game.hpp"

void Game::initVars() {
    this->window = nullptr;

    // So game starts on menu
    this->state = GameState::Menu;
}

void Game::initFonts() {
    this->font.openFromFile("assets/font.ttf");
}

void Game::initText() {
    this->titleText.setFont(this->font);
    this->titleText.setString("SNAKE");
    this->titleText.setCharacterSize(60);
    this->titleText.setFillColor(sf::Color::Green);
    this->titleText.setPosition({200.f, 150.f});

    this->startText.setFont(this->font);
    this->startText.setString("Press Enter to Play");
    this->startText.setCharacterSize(24);
    this->startText.setFillColor(sf::Color::White);
    this->startText.setPosition({170.f, 300.f});
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode({600, 600}), "Snake Game", sf::Style::Titlebar | sf::Style::Close);
}


// Finish menu from this point downwards
void Game::pollEvents() {
    while (const auto event = this->window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            this->window->close();
        }
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->code == sf::Keyboard::Key::Escape) {
                this->window->close();
            }
        }
    }
}

void Game::update() {
    this->pollEvents();
}

void Game::render() {
    this->window->clear(sf::Color(20, 20, 20));
    b.render(*this->window);
    this->window->display();
}

Game::Game() {
    this->initVars();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}
