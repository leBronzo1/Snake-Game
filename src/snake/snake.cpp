#include "snake.hpp"

Snake::Snake() {
    len = 1;
    points_pairs.push_back(std::make_pair(0, 0));
}