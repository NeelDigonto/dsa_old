#include <iostream>
#include <utility>
#include <vector>

#include <limits>
#include <array>
#include <string>


namespace Q3 {

    class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {

            using value_type = std::string::value_type;

            constexpr size_t range = std::numeric_limits<value_type>::max() - std::numeric_limits<value_type>::min() + static_cast<std::size_t>(1);
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

                character_hashes[ch] = static_cast<int>(index);
                max_length = std::max(max_length, index - substr_start);

            }

            return static_cast<int>(max_length);
        }
    };

    bool test()
    {
        const std::vector<std::pair<std::string, int>> test_cases{ {"abcabcbb", 3}, {"bbbbb", 1}, {"pwwkew", 3}, {" ", 1}, {"dvdf", 3}, {"abba", 2}, {"au", 2} };


        Solution solution;

        for (const auto& test_case : test_cases) {
            std::cout << solution.lengthOfLongestSubstring(test_case.first) << std::endl;
        }

        return true;
    }


}