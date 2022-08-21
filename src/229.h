#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <numeric> // for gcd

#include <limits>
#include <array>
#include <string>
#include <unordered_map>

namespace Q229 {

    class Solution {
    public:
        std::vector<int> majorityElement(std::vector<int>& nums) {
            std::unordered_map<int, std::size_t> hashes;
            const std::size_t n = nums.size();

            for (const auto& num : nums) {
                hashes[num]++;
            }

            std::vector<int> elems;
            for (const auto& hash : hashes) {
                if (hash.second > n / 3)
                {
                    elems.push_back(hash.first);
                }
            }
            return elems;
        }
    };


    bool test()
    {

        std::vector<std::pair<std::vector<int>, std::vector<int>>> test_cases{
            { {3, 2, 3} , {3} },
            { {1}, {1} },
            { {1, 2}, {1, 2}}
        };

        Solution solution;

        for (auto& test_case : test_cases) {
            for (auto& elem : solution.majorityElement(test_case.first)) {
                std::cout << elem << ", ";
            }
            std::cout << std::endl;
        }

        return true;
    }
}