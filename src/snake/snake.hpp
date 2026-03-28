#pragma once

#include <iostream>
#include <vector>
#include <utility>

class Snake {
    private:
        int len;
        std::vector<std::pair<int, int>> points_pairs;
        bool alive;
    public:
        Snake();
};