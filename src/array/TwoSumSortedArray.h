#pragma once
#include <core/Common.h>

namespace TwoSumSortedArray {

    class Solution {
    public:
        vector<int> twoSum(const vector<int>& numbers, int target) {
            for (auto it = numbers.begin(); it != numbers.end() - 1; ++it) {
                const int first_elem_dist = distance(numbers.begin(), it);
                const auto complement = target - *it;

                auto it2 = lower_bound(it + 1, numbers.end(), complement);
                if (it2 != numbers.end() && * it2 == complement) {
                    const int second_elem_dist = distance(numbers.begin(), it2);
                    const vector<int> ret{ first_elem_dist + 1, second_elem_dist + 1 };
                    return ret;
                }
            }
            return {};
        }
    };

    void test() {
        {
            auto const result = Solution{}.twoSum({ 2, 7, 11, 15 }, 9);
            const decltype(result) ans = { 1, 2 };
            cout << boolalpha << equal(result.begin(), result.begin(), ans.begin()) << endl;
        }

        {
            auto const result = Solution{}.twoSum({ 1, 3, 4, 4 }, 8);
            const decltype(result) ans = { 3, 4 };
            cout << boolalpha << equal(result.begin(), result.begin(), ans.begin()) << endl;
        }
    }
}