#pragma once
#include <core/Common.h>

namespace MinimumPathCostGrid {

	class Solution {
	public:
		int minPathCost(const vector<vector<int>>& grid, const vector<vector<int>>& moveCost) {
			const auto m = grid.size();
			const auto n = grid.cbegin()->size();
			vector<vector<int>> memo(m, vector<int>(n, {}));

			for (size_t col = 0; col != n; ++col) {
				memo[0][col] = grid[0][col];
			}

			for (size_t row = 1; row != m; ++row) {
				for (size_t col = 0; col != n; ++col) {
					int min_cost = numeric_limits<int>::max();
					for (size_t prevcol = 0; prevcol != n; ++prevcol) {
						const auto& cell_cost = grid[row][col];
						const auto& from_cell = grid[row - 1][prevcol];
						const auto& path_cost = moveCost[from_cell][col] + memo[row -1][prevcol];

						const auto total_cost = cell_cost + path_cost;
						min_cost = min(min_cost, total_cost);
					}
					memo[row][col] = min_cost;
				}
			}

			return *min_element(memo[m - 1].cbegin(), memo[m - 1].cend());
		}

	};

	void test() {
		cout << Solution{}.minPathCost({ {5,3},{4,0 }, { 2,1 } }, { {9,8},{1,5}, {10,12}, {18,6}, {2,4}, {14,3 } }) << endl;
		cout << Solution{}.minPathCost({ {5, 1, 2}, {4, 0, 3} }, { {12, 10, 15}, {20, 23, 8}, {21, 7, 1}, {8, 1, 13}, {9, 10, 25}, {5, 3, 2} }) << endl;
	}

}