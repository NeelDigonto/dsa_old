#pragma once
#include "core/Common.h"

namespace FrogJump {


	int _frogJumpRec(int n, const vector<int>& heights) {
		if (n == 0) return 0;

		int stepdown1 = _frogJumpRec(n - 1, heights) + std::abs(heights[n] - heights[n - 1]);
		int stepdown2 = std::numeric_limits<int>::max();
		if(n != 1)
			stepdown2 = _frogJumpRec(n - 2, heights) + std::abs(heights[n] - heights[n - 2]);

		return std::min(stepdown1, stepdown2);
	}

	int frogJumpRec(int n, const vector<int>& heights)
	{
		return _frogJumpRec(n - 1, heights);
	}

	int _frogJumpMemo(int n, const vector<int>& heights, vector<optional<int>>& memo) {
		if (n == 0) return 0;

		if (memo[n].has_value()) return memo[n].value();

		int stepdown1 = _frogJumpMemo(n - 1, heights, memo) + std::abs(heights[n] - heights[n - 1]);
		int stepdown2 = std::numeric_limits<int>::max();
		if (n != 1)
			stepdown2 = _frogJumpMemo(n - 2, heights, memo) + std::abs(heights[n] - heights[n - 2]);

		memo[n] = std::min(stepdown1, stepdown2);

		return memo[n].value();
	}

	int frogJumpMemo(int n, const vector<int>& heights) {
		vector<optional<int>> memo(n, std::nullopt);

		return _frogJumpMemo(n - 1, heights, memo);
	}

	int frogJumpTab(int n, const vector<int>& heights) {
		if (n == 0) return 0;
		if (n == 1) return std::abs(heights[1] - heights[0]);
		
		vector<int> memo(n, 0);

		memo[0] = 0;
		memo[1] = std::abs(heights[1] - heights[0]);

		for (size_t i = 2; i != n; ++i) {
			int stepdown1 = memo[i-1] + std::abs(heights[i] - heights[i - 1]);

			int stepdown2 = memo[i-2] + std::abs(heights[i] - heights[i - 2]);

			memo[i] = std::min(stepdown1, stepdown2);
		}


		return memo[n-1];
	}

	int frogJumpSO(int n, const vector<int>& heights) {
		if (n == 0) return 0;
		if (n == 1) return heights[1] - heights[0];

		int prev2 = 0;
		int prev = std::abs(heights[1] - heights[0]);

		for (size_t i = 2; i != n; ++i) {
			int stepdown1 = prev + std::abs(heights[i] - heights[i - 1]);
			int stepdown2 = prev2 + std::abs(heights[i] - heights[i - 2]);

			int temp = std::min(stepdown1, stepdown2);
			prev2 = prev;
			prev = temp;
		}


		return prev;
	}

	int frogJump(int n, const vector<int>& heights)
	{
		//return frogJumpRec(n, heights);
		//return frogJumpMemo(n, heights);
		//return frogJumpTab(n, heights);
		return frogJumpTab(n, heights);
	}

	class Solution {
	public:
		constexpr pair<size_t, size_t> _index(size_t _n, size_t n) {
			return { _n / n, _n % n };
		}
		bool searchMatrix(vector<vector<int>>&& matrix, int target) {
			size_t m = matrix.size(), n = matrix[0].size(), _n = n * m;
			int left = 0, right = _n - 1;

			while (left <= right) {
				int mid = (left + right) / 2;
				auto [i, j] = _index(mid, n);

				if (matrix[i][j] == target) return true;

				else if (matrix[i][j] < target) left = mid + 1;

				else if (matrix[i][j] > target) right = mid - 1;
			}

			return false;
		}
	};

	void test() {

		cout << frogJump(4, {10, 20, 30, 10}) << endl;


		Solution{}.searchMatrix({ {1, 3} }, 3);

	}
}

