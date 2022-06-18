#pragma once
#include <core/Common.h>

namespace SlidingWindowMaximum {

    class Solution {
    public:
        template<typename FwdIt>
        auto _maxSlidingWindow(FwdIt _first, FwdIt _last, size_t _window_size)
        -> vector<typename FwdIt::value_type> {
            const auto n = distance(_first, _last);
            using val_t = typename FwdIt::value_type;
            // [1,3,-1,-3,5,3,6,7]
            if (_window_size >= n)
                return vector<val_t>{*max_element(_first, _last)};
            else {
                map<val_t, FwdIt, greater<val_t>> map;
                FwdIt left = _first, right = next(_first, _window_size);
                for (auto it = left; it != right; ++it)
                    map[*it] = it;

                vector<val_t> windows;
                windows.reserve(n);
                windows.push_back(map.begin()->first);
                left++;

                while (right != _last) {
                    //remove prev el
                    auto found = map.find(*prev(left));
                    if (found->second == prev(left))
                        map.erase(found->first);
                    //insert new element
                    map[*right] = right;

                    windows.push_back(map.begin()->first);

                    left++;
                    right++;
                }

                return windows;
            }

        }

        vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
            return _maxSlidingWindow(nums.cbegin(), nums.cend(), k);
        }
    };

    void test() {
        cout << Solution{}.maxSlidingWindow({ 1, 3, -1, -3, 5, 3, 6, 7 }, 3);
        cout << Solution{}.maxSlidingWindow({ 1 }, 1);
        cout << Solution{}.maxSlidingWindow({ 1, -1 }, 1);
        cout << Solution{}.maxSlidingWindow({ 1, 3, 1, 2, 0, 5 }, 3);
        cout << Solution{}.maxSlidingWindow({ 9, 10, 9, -7, -4, -8, 2, -6 }, 5);
    }

}