#include <iostream>
#include <vector>

namespace Q48 {

    class Solution {
    public:
        void rotate(std::vector<std::vector<int>>& matrix) {
            const std::size_t n = matrix.size();

            // first transpose it
            for (std::size_t i = 0; i < n; ++i) {
                for (std::size_t j = i + 1; j < n; ++j) {
                    const int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }

            // then invert it along the vertical axis or reflect it
            for (std::size_t i = 0; i < n; ++i) {
                for (std::size_t j = 0; j < n / 2; ++j) {
                    const int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][n - j - 1];
                    matrix[i][n - j - 1] = temp;
                }
            }
        }
    };

    bool test()
    {
        std::vector<std::vector<int>> matrix1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
        std::vector<std::vector<int>> matrix2 = { { 5,1,9,11 }, { 2,4,8,10 }, { 13,3,6,7 }, { 15,14,12,16 } };


        Solution solution;

        solution.rotate(matrix2);

        for (const std::vector<int>& v : matrix2)
        {
            for (int x : v) std::cout << x << ' ';
            std::cout << std::endl;
        }



        return true;
    }
}