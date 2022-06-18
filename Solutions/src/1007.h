#include <iostream>
#include <utility>
#include <vector>

#include <limits>
#include <array>
#include <string>
#include <algorithm>


namespace Q1007 {

    class Solution {
    public:
        int minDominoRotations(std::vector<int>& tops, std::vector<int>& bottoms) {
            
            std::array<unsigned int, 7> store{};
            int repeat_count = 0;

            for (std::size_t i = 0; i != tops.size(); ++i) {

                if (tops[i] != bottoms[i]) {
                    store[tops[i]]++;
                    store[bottoms[i]]++;
                }
                else {
                    store[tops[i]]++;
                    repeat_count++;
                }
            }

            const auto max_elem_iter = std::max_element(store.begin(), store.end());
            unsigned int number_repeated_most = std::distance(store.begin(), max_elem_iter);
            unsigned int max_occurence = *max_elem_iter;

            if (max_occurence < tops.size()) {
                return -1;
            }

            std::size_t min_rotations = 0;

            for (std::size_t i = 0; i != tops.size(); ++i) {

                if (tops[i] != number_repeated_most) {
                    min_rotations++;
                }
            }

            
            return std::min(min_rotations, tops.size() - repeat_count - min_rotations);

        }
    };

    bool test()
    {
        struct Params {
            std::vector<int> tops;
            std::vector<int> bottoms;

            //Params(decltype(tops) _tops, decltype(bottoms) _bottoms) : tops{ _tops }, bottoms{_bottoms} {}
        };

        struct TestCase {
            Params params;
            int result;

            //TestCase(decltype(params) _params, decltype(result) _result) : params{ _params }, result{ _result } {}
        };

        std::vector<TestCase> test_cases{
             TestCase(Params({2, 1, 2, 4, 2, 2}, {5, 2, 6, 2, 3, 2}), 2),
             TestCase(Params({ 3, 5, 1, 2, 3 }, { 3, 6, 3, 3, 4 }), -1),
             TestCase(Params({ 1, 2, 1, 1, 1, 2, 2, 2 }, 
                             { 2, 1, 2, 2, 2, 2, 2, 2 }), 1),
        };


        Solution solution;

        for (auto& test_case : test_cases) {
            std::cout << solution.minDominoRotations(test_case.params.tops, test_case.params.bottoms) << std::endl;
        }

        return true;
    }


}