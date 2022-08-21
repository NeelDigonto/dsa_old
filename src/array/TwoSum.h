#pragma once
#include <core/Common.h>

namespace Random {
    // O(n^2)
    // O(nlogn)
    // O(n)
    class Solution {
    public:
        vector<int> twoSum(const vector<int>& nums, int target) {
            const int n = nums.size();

            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                    if (nums[i] + nums[j] == target)
                        return { i, j };
            return {};
        }
    };

    void test() {
        cout << Solution{}.twoSum({ 2,7,11,15 }, 9) << endl;
        cout << Solution{}.twoSum({ 3,2,4 }, 6) << endl;
        cout << Solution{}.twoSum({ 3,3 }, 6) << endl;
    }

}