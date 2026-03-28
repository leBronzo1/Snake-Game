#include "game.hpp"

void Game::initVars() {
    this->window = nullptr;
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode({600, 600}), "Snake Game", sf::Style::Titlebar | sf::Style::Close);
}

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
