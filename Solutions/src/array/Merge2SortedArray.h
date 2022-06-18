#pragma once
#include <core/Common.h>

namespace Merge2SortedArray {

    class Solution {
    public:
        void merge(vector<int>& nums1, size_t m, const vector<int>& nums2, size_t n) {
            constexpr size_t npos = -1;
            size_t back_pointer = m + n - 1;
            m--; n--;
            while (n != npos) {
                if (m != npos && nums1[m] >= nums2[n])
                    nums1[back_pointer--] = nums1[m--];
                else 
                    nums1[back_pointer--] = nums2[n--];
            }
        }
    };


    void test() {
        vector<int> nums1{ 1,2,3,0,0,0 }, nums2{ 2,5,6 }, ans{ 1, 2, 2, 3, 5, 6 };
        Solution{}.merge(nums1, 3, nums2, 3);
        cout << boolalpha << equal(nums1.begin(), nums1.end(), ans.begin());
    }
}