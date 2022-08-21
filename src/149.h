#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <numeric> // for gcd

#include <limits>
#include <array>
#include <string>
#include <unordered_map>

namespace Q149 {

    class Solution {
    public:
        int maxPoints(std::vector<std::vector<int>>& points) {
            int max_points = 1;
            if (points.size() == 1) return max_points;
            for (int i = 0; i < points.size() - 1; i++)
            {
                std::unordered_map<double, int> line_hashes;
                for (int j = i + 1; j < points.size();j++)
                {
                    if ((points[j][0] - points[i][0]) == 0)
                    {
                        line_hashes[std::numeric_limits<int>::max()]++;
                    }
                    else
                    {
                        double slope = ((double)points[j][1] - (double)points[i][1]) / ((double)points[j][0] - (double)points[i][0]);
                        line_hashes[slope]++;
                    }
                }

                for (const auto& it : line_hashes)
                {
                    max_points = std::max(max_points, it.second);
                }
            }
            return max_points + 1;
        }
    };


    bool test()
    {
        std::vector<std::pair<std::vector<std::vector<int>>, int>> test_cases{
            { { {1,1},{2,2},{3,3} }, 3},
            { { { {1,1},{3,2},{5,3},{4,1},{2,3},{1,4}} }, 4 },
            { { {0, 0} }, 1}
        };

        Solution solution;

        for (auto& test_case : test_cases) {
            std::cout << solution.maxPoints(test_case.first) << std::endl;
        }

        return true;
    }
}