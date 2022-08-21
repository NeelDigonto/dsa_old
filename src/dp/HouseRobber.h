#pragma once

#include "core/Common.h"
namespace HouseRobber {
    constexpr int SENTINEL = -1;
    class Solution {
    public:

        int _robMemo(int i, const vector<int>& nums, vector<int>& memo) {
            if (i == 0) return nums[0];

            if (memo[i] != SENTINEL) return memo[i];

            int incl = nums[i];
            if(i != 1)
                incl += _robMemo(i - 2, nums, memo);
            int not_incl = _robMemo(i - 1, nums, memo);

            return memo[i] = max(incl, not_incl);

        }

        int robMemo(const vector<int>& nums) {
            const int n = nums.size();
            vector<int> memo(n, SENTINEL);
            return _robMemo(n - 1, nums, memo);
        }


        int robTab(const vector<int>& nums) {
            const size_t n = nums.size();
            if (n == 1) return nums[0];
            vector<int> memo(n, SENTINEL);
            
            memo[0] = nums[0];
            memo[1] = max(nums[1], nums[0]);

            for (size_t i = 2; i != n; ++i) {
                int incl = nums[i] + memo[i-2];
                int not_incl = memo[i-1];

                memo[i] = max(incl, not_incl);
            }
            
            return memo[n-1];
        }

        int robSO(const vector<int>& nums) {
            const size_t n = nums.size();
            if (n == 1) return nums[0];

            int prev2 = nums[0];
            int prev = max(nums[1], nums[0]);

            for (size_t i = 2; i != n; ++i) {
                int incl = nums[i] + prev2;
                int not_incl = prev;

                int temp = max(incl, not_incl);
                prev2 = prev;
                prev = temp;
            }

            return prev;
        }

        int rob(const vector<int>& nums) {
            //return robMemo(nums);
        }
    };

    void test() {

        cout << Solution{}.robMemo({ 1, 2, 3, 1 }) << endl;
        cout << Solution{}.robMemo({ 2, 1 }) << endl;
        cout << Solution{}.robMemo({ 0 }) << endl;
        cout << Solution{}.robTab({ 1, 2, 3, 1 }) << endl;
        cout << Solution{}.robTab({ 2, 1 }) << endl;
        cout << Solution{}.robTab({ 0 }) << endl;
        cout << Solution{}.robSO({ 1, 2, 3, 1 }) << endl;
        cout << Solution{}.robSO({ 2, 1 }) << endl;
        cout << Solution{}.robSO({ 0 }) << endl;
    }
}
