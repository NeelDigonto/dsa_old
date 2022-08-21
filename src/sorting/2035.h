#include <iostream>
#include <utility>
#include <vector>

#include <limits>
#include <array>
#include <string>
#include <algorithm>


namespace Q2035 {

    class Solution {
    public:
        int minimumDifference(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());

            int first_sum = 0;
            int second_sum = 0;

            auto iter = nums.begin();
            while (iter != nums.end()) {
                first_sum += *iter++;
                second_sum += *iter++;
            }

            return std::abs(first_sum - second_sum);
        }
    };

    bool test()
    {
        std::vector<std::pair<std::vector<int>,int>> test_cases{ 
            { {3, 9, 7, 3}, 2},
            { {-36, 36}, 72},
            { {2, -1, 0, 4, -2, -9}, 0}
        };


        Solution solution;

        for (auto& test_case : test_cases) {
            std::cout << solution.minimumDifference(test_case.first) << std::endl;
        }

        return true;
    }


}