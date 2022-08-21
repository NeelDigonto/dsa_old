#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <numeric> // for gcd

#include <limits>
#include <array>
#include <string>
#include <unordered_map>

namespace Q139 {

    class Solution {
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
            std::unordered_map<std::string, bool> dictionary;

            for (const auto& dict_word : wordDict) {
                dictionary.insert(std::make_pair(dict_word, true));
            }

            size_t start = 0;
            for (std::size_t index = 0; index != s.size(); ++index) {
                const std::string current_search = s.substr(start, index + 1 - start);

                if (dictionary.find(current_search) != dictionary.end()) {
                    start = index + 1;
                }
            }

            if (start == s.size())
                return true;
            else
                return false;
        }
    };


    bool test()
    {
        struct Param {
            std::string s;
            std::vector<std::string> wordDict;
        };

        std::vector<std::pair<Param, bool>> test_cases{
            /* {{"leetcode", {"leet","code"}}, true},
             { {"applepenapple", {"apple","pen"} }, true},
             { {"catsandog", {"cats","dog","sand","and","cat"} }, false},*/
             { {"aaaaaaa", {"aaaa", "aaa"} }, true},
        };

        Solution solution;

        for (auto& test_case : test_cases) {
            std::cout << solution.wordBreak(test_case.first.s, test_case.first.wordDict) << std::endl;
        }

        return true;
    }
}