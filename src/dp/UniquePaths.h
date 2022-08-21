#pragma once
#include <core/Common.h>
#include <core/vector_math.h>

namespace UniquePaths {

	class Solution {
	public:
		using vec2 = basic_vec2<size_t>;
		static constexpr auto sloc = vec2{ 0,0 };
		vec2 floc{};
		static constexpr size_t npos = -1;
		
	private:
		size_t uniquePathsMemo(vec2 _loc, vector<vector<size_t>>& memo) {
			if (_loc == sloc)
				return 1;

			bool out_of_bound = _loc.x == npos || _loc.y == npos;
			if (out_of_bound) return 0;

			auto& cache_loc = memo[_loc.x][_loc.y];
			if (cache_loc != npos) return cache_loc;

			size_t right = uniquePathsMemo({ _loc.x - 1, _loc.y }, memo);
			size_t down = uniquePathsMemo({ _loc.x, _loc.y - 1 }, memo);

			return cache_loc = right + down;
		}

		size_t uniquePathsMemo(size_t m, size_t n) {
			vector<vector<size_t>> memo(m, vector<size_t>(n, npos));
			return uniquePathsMemo({ static_cast<size_t>(m - 1), static_cast<size_t>(n - 1) }, memo);
		}

		size_t uniquePathsTab(size_t m, size_t n) {
			vector<vector<size_t>> memo(m, vector<size_t>(n, 0));

			memo[0][0] = 1;

			for (size_t col = 1; col != n; ++col)
				memo[0][col] = 1;

			for (size_t row = 1; row != m; ++row)
				memo[row][0] = 1;

			for (size_t row = 1; row != m; ++row) {
				for (size_t col = 1; col != n; ++col) {
					memo[row][col] = memo[row - 1][col] + memo[row][col - 1];
				}
			}

			return memo[m - 1][n - 1];
		}

		size_t uniquePathsSO(size_t m, size_t n) {

			if (m == 1 || n == 1) return 1;

			vector<size_t> memo(n, 0);

			memo[0] = 1;

			for (size_t col = 1; col != n; ++col)
				memo[col] = 1;

			size_t prev_left = 1;
			size_t up = 0;

			for (size_t row = 1; row != m; ++row) {
				for (size_t col = 1; col != n; ++col) {
					up = memo[col];
					memo[col] = prev_left + up;
					prev_left += up;
				}
				prev_left = 1;
				up = 1;
			}

			return memo[n - 1];
		}

		size_t uniquePathsPC(size_t m, size_t n) {

			size_t N = n + m - 2;
			size_t r = m - 1;
			double res = 1;

			for (int i = 1; i <= r; ++i) {
				res = res * (N - r + i) / i;
			}
			return static_cast<size_t>(res);
		}

	public:
		int uniquePaths(int m, int n) {

			//return uniquePathsMemo(m, n);
			//return uniquePathsTab(m, n);
			return uniquePathsSO(m, n);
			//return uniquePathsPC(m, n);
		}

	};

	void test() {
		cout << Solution{}.uniquePaths(3, 7) << endl;
		cout << Solution{}.uniquePaths(3, 2) << endl;
		cout << Solution{}.uniquePaths(2, 2) << endl;
	}

}