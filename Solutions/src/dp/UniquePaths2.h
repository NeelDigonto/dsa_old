#pragma once
#include <core/Common.h>

namespace UniquePaths2 {

	class Solution {
		using vec2 = basic_vec2<size_t>;
		static constexpr size_t npos = -1;
	private:
		size_t uniquePathsWithObstaclesMemo(size_t row, size_t col, const vector<vector<int>>& obstacleGrid, vector<vector<size_t>>& memo) {
			const auto m = obstacleGrid.size();
			const auto n = obstacleGrid.begin()->size();

			if (row == 0 && col == 0) {
				if (obstacleGrid[row][col] == 1) return 0;
				else return 1;
			}
			if (row == npos || col == npos || obstacleGrid[row][col] == 1) return 0;

			if (memo[row][col] != npos) return memo[row][col];

			const auto left = uniquePathsWithObstaclesMemo(row, col - 1, obstacleGrid, memo);
			const auto up = uniquePathsWithObstaclesMemo(row - 1, col, obstacleGrid, memo);

			return memo[row][col] = left + up;
		}

		size_t uniquePathsWithObstaclesMemo(const vector<vector<int>>& obstacleGrid) {
			const auto m = obstacleGrid.size();
			const auto n = obstacleGrid.begin()->size();
			vector<vector<size_t>> memo(m, vector<size_t>(n, npos));

			return uniquePathsWithObstaclesMemo(obstacleGrid.size() - 1, obstacleGrid.begin()->size() - 1, obstacleGrid, memo);
		}

		size_t uniquePathsWithObstaclesTab(const vector<vector<int>>& obstacleGrid) {
			const auto m = obstacleGrid.size();
			const auto n = obstacleGrid.begin()->size();
			vector<vector<size_t>> memo(m, vector<size_t>(n, 0));

			for (size_t row = 0; row != m; ++row) {
				if (obstacleGrid[row][0] == 1) break;
				else memo[row][0] = 1;
			}

			for (size_t col = 0; col != n; ++col) {
				if (obstacleGrid[0][col] == 1) break;
				else memo[0][col] = 1;
			}

			for (size_t row = 1; row != m; ++row) {
				for (size_t col = 1; col != n; ++col) {
					if (obstacleGrid[row][col] == 1)
						memo[row][col] = 0;
					else
						memo[row][col] = memo[row - 1][col] + memo[row][col - 1];
				}
			}

			return memo[m - 1][n - 1];

		}

	public:
		int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
			//return uniquePathsWithObstaclesMemo(obstacleGrid);
			return uniquePathsWithObstaclesTab(obstacleGrid);
		}
	};

	void test() {
		cout << Solution{}.uniquePathsWithObstacles({ {0,0,0}, {0,1,0 }, { 0,0,0 } }) << endl;
		cout << Solution{}.uniquePathsWithObstacles({ {0, 1}, {0, 0} }) << endl;

	}

}