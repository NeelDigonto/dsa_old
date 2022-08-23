#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <numeric> // for gcd

#include <limits>
#include <array>
#include <string>
#include <unordered_map>

namespace Q169 {

    class Solution {
    public:
        int majorityElement(std::vector<int>& nums) {
            std::unordered_map<int, int> hashes;

            for (const auto& num : nums) {
                hashes[num]++;
            }

            int max = 0;
            int elem = nums[0];
            for (const auto& hash : hashes) {
                if (max < hash.second)
                {
                    max = hash.second;
                    elem = hash.first;
                }
            }

            return elem;
        }
    };


    bool test()
    {

        std::vector<std::pair<std::vector<int>, int>> test_cases{
            { {3, 2, 3} , 3 },
            { {2, 2, 1, 1, 1, 2, 2}, 2 }
        };

        Solution solution;

        for (auto& test_case : test_cases) {
            std::cout << solution.majorityElement(test_case.first) << std::endl;
        }

        return true;
    }
}