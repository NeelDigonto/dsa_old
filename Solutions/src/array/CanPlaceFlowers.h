#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <optional>
#include <stack>
#include <iostream>
#include <utility>

namespace Q605 {

    class Solution {
    public:
        bool canPlaceFlowers(std::vector<int>&& flowerbed, int n) {

            flowerbed.insert(flowerbed.begin(), 0);
            flowerbed.push_back(0);

            std::size_t count{ 0 };

            for (std::size_t i = 0; i < flowerbed.size() - 2; i++) {
                if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i + 2] == 0) {
                    count++;
                    flowerbed[i + 1] = 1;
                }
            }

            return count >= n;
        }
    };
}