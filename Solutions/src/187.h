#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <numeric> // for gcd

#include <limits>
#include <array>
#include <string>
#include <unordered_map>

namespace Q187 {

    class Solution {
    public:
        std::vector<std::string> findRepeatedDnaSequences(std::string s) {

            std::unordered_map<std::string, std::size_t> hashes;
            const auto n = s.size();
            std::vector<std::string> result;
            result.reserve(10);

            if (n < 10)
                return result;

            for (std::size_t index = 0; index <= n - 10; ++index) {
                hashes[s.substr(index, 10)]++;
            }

            for (const auto& hash : hashes) {
                if (hash.second > 1) {
                    result.push_back(hash.first);
                }
            }

            return result;
        }
    };


    bool test()
    {

        std::vector<std::pair<std::string, std::vector<std::string>>> test_cases{
            {"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", {"AAAAACCCCC", "CCCCCAAAAA"}},
            { "AAAAAAAAAAAAA", {"AAAAAAAAAA"} },
            {"AAAAAAAAAAA", {"AAAAAAAAAA"} }
        };

        Solution solution;

        for (auto& test_case : test_cases) {
            for (auto& elem : solution.findRepeatedDnaSequences(test_case.first)) {
                std::cout << elem << ", ";
            }
            std::cout << std::endl;
        }

        return true;
    }
}