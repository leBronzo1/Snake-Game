#include "board.hpp"

Board::Board() {
    std::random_device rd;
    gen = std::mt19937(rd());
    distr = std::uniform_int_distribution<int>(0, GRID_SIZE - 1);

    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = square::empty;
        }
    }

    
    spawnFood();
}

void Board::spawnFood() {
    int r, c;
    bool placed = false;

    while (!placed) {
        // Coordinate Generation
        r = distr(gen); 
        c = distr(gen);

        if (grid[r][c] == square::empty) {
            grid[r][c] = square::fruit;
            fruitPos = {r, c}; // Keep track of fruit position
            placed = true;
        }
    }
}

bool Board::update() {
    snake.updatePos();

    sf::Vector2i head = snake.getHead();

    if (head.x < 0 || head.x >= GRID_SIZE || head.y < 0 || head.y >= GRID_SIZE) {
        return true; // game over
    }

    std::deque<sf::Vector2i> body = snake.retVec();

    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            sf::Vector2i pos(x, y);

            bool isSnake = false;
            for (const auto& segment : body) {
                if (segment == pos) {
                    isSnake = true;
                    break;
                }
            }

            if (isSnake) {
                grid[x][y] = square::snaked;
            } else if (pos == fruitPos) {
                grid[x][y] = square::fruit;
            } else {
                grid[x][y] = square::empty;
            }
        }
    }

    return false;
}

bool Board::isFood(sf::Vector2i pos) {
    return false;
}

bool Board::isOutOfBounds(sf::Vector2i pos) {
    return false;
}

void Board::render(sf::RenderWindow &window) {
    sf::RectangleShape cell({CELL_SIZE - 2.f, CELL_SIZE - 2.f}); // 2px gap

    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            switch (grid[x][y]) {
                case square::empty:
                    cell.setFillColor(sf::Color::Black);
                    break;
                case square::fruit:
                    cell.setFillColor(sf::Color::Red);
                    break;
                case square::snaked:
                    cell.setFillColor(sf::Color::Green);
                    break;
            }
            cell.setPosition({static_cast<float>(x * CELL_SIZE), static_cast<float>(y * CELL_SIZE)});
            window.draw(cell);
        }
    }
}
