#include "snake.hpp"

Snake::Snake() {
    len = 1;
    this->body.push_front({10,10});
    cDirr = Direction::Right;
}

void Snake::updatePos() {
    sf::Vector2i newHead = body.front(); // copy current head

    switch(cDirr) {
        case Direction::Up:    newHead += sf::Vector2i(0, -1); break;
        case Direction::Right: newHead += sf::Vector2i(1,  0); break;
        case Direction::Left:  newHead += sf::Vector2i(-1, 0); break;
        case Direction::Down:  newHead += sf::Vector2i(0,  1); break;
    }

    body.push_front(newHead); // add new head
    body.pop_back();          // remove tail
}

sf::Vector2i Snake::getHead() const {
    return body.front();
}