#pragma once
#include <core/Common.h>

namespace MinimumPathSum {

	class Solution {
	public:
		int minPathSum(const vector<vector<int>>& grid) {
			const auto m = grid.size();
			const auto n = grid.cbegin()->size();
			vector<vector<int>> memo(m, vector<int>(n, {}));

			memo[0][0] = grid[0][0];

			for (size_t row = 1; row != m; ++row)
				memo[row][0] = memo[row - 1][0] + grid[row][0];

			for (size_t col = 1; col != n; ++col)
				memo[0][col] = memo[0][col - 1] + grid[0][col];

			for (size_t row = 1; row != m; ++row) {
				for (size_t col = 1; col != n; ++col) {
					const auto& up = memo[row - 1][col];
					const auto& left = memo[row][col - 1];
					memo[row][col] = min(left, up) + grid[row][col];
				}
			}

			return memo[m - 1][n - 1];
		}
	};

	void test() {
		cout << Solution{}.minPathSum({ {1,3,1}, {1,5,1 }, { 4,2,1 } }) << endl;
		cout << Solution{}.minPathSum({ {1,2,3}, {4,5,6 } }) << endl;

	}

}