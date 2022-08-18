#pragma once
#include <core/Common.h>

namespace NextPermutation {

    class Solution {
    public:
        template<typename BidIt, typename Pred>
        bool _nextPermutation(BidIt _first, BidIt _last, Pred _pred) {
            return false;
        }

        void nextPermutation(vector<int>& nums) {
            //next_permutation(nums.begin(), nums.end());
            _nextPermutation(nums.begin(), nums.end(), std::less<int>{});

        }
    };

    void test() {
        vector<int> set{ 1,2,3 };
        Solution{}.nextPermutation(set);
        cout << set << endl;

        set = { 3,2,1 };
        Solution{}.nextPermutation(set);
        cout << set << endl;

        set = { 1,1,5 };
        Solution{}.nextPermutation(set);
        cout << set << endl;
    }

}