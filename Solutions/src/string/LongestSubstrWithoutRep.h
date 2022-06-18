#pragma once
#include <core/Common.h>

namespace LongestSubstrWithoutRep {

    class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {

            using value_type = std::string::value_type;

            constexpr size_t range = std::numeric_limits<value_type>::max() - std::numeric_limits<value_type>::min() + 1;
            constexpr size_t size_t_max = std::numeric_limits<std::size_t>::max();

            std::array<int, range> character_hashes;
            character_hashes.fill(-1);

            std::size_t max_length = 0;
            int substr_start = -1;

            for (std::size_t index = 0; index != s.length(); ++index) {

                const value_type& ch = s[index];
                if (character_hashes[ch] > substr_start) {

                    substr_start = character_hashes[ch];
                }

                character_hashes[ch] = index;
                max_length = std::max(max_length, index - substr_start);

            }

            return max_length;
        }
    };

    void test() {
        //cout << Solution{}.lengthOfLongestSubstring("abcabcbb") << endl;//3
        //cout << Solution{}.lengthOfLongestSubstring("bbbbb") << endl;//1
        //cout << Solution{}.lengthOfLongestSubstring("pwwkew") << endl;//3
        cout << Solution{}.lengthOfLongestSubstring("aabaab!bb") << endl;//3
    }

}