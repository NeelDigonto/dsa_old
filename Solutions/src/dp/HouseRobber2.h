#pragma once

#include "core/Common.h"
namespace HouseRobber2 {
    class Solution {
    public:

        int robSO(vector<int>::const_iterator _first, vector<int>::const_iterator _last) {

            const size_t n = distance(_first, _last);

            int prev2 = *_first;
            int prev = max(*_first, *(++_first));

            for (auto it = ++_first; it != _last; ++it) {
                int incl = *it + prev2;
                int not_incl = prev;

                int temp = max(incl, not_incl);
                prev2 = prev;
                prev = temp;
            }

            return prev;
        }

        int robSO(const vector<int>& nums) {
            const size_t n = nums.size();

            if (n == 1) return nums[0];
            if (n == 2) return max(nums[0], nums[1]);
            
            const int first = robSO(nums.begin(), nums.end() - 1);
            const int last = robSO(nums.begin() + 1, nums.end());
            return max(first, last);

        }

        int rob(const vector<int>& nums) {
            //return robMemo(nums);
            return robSO(nums);
        }

    };

    void test() {
        cout << Solution{}.robSO({ 2, 3, 2 }) << endl;
        cout << Solution{}.robSO({ 1, 2, 3, 1 }) << endl;
        cout << Solution{}.robSO({ 1, 2, 3 }) << endl;
        cout << Solution{}.robSO({ 0, 0 }) << endl;
        cout << Solution{}.robSO({ 2, 7, 9, 3, 1 }) << endl;
    }
}