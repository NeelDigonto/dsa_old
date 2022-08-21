#pragma once
#include <core/Common.h>

namespace Triangle {

	class Solution {
	public:
		int minimumTotal(const vector<vector<int>>& triangle) {
			const auto m = triangle.size();
			if (m == 1) return triangle[0][0];
			constexpr size_t npos = -1;
			vector<int> memo(triangle.back());


			for (size_t row = m - 2; row != npos; --row) {
				for (size_t col = 0; col != row + 1; ++col) {
					const int cost = min(memo[col], memo[col + 1]) + triangle[row][col];
					memo[col] = cost;
				}
			}

			return memo[0];
		}
	};

	void test() {
		cout << Solution{}.minimumTotal({ {2}, {3,4}, {6,5,7}, {4,1,8,3 } }) << endl;
		cout << Solution{}.minimumTotal({ {-10} }) << endl;
	}
}