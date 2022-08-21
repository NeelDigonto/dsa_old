#pragma once

#include <core/Common.h>

namespace SubsetSumToK {

	constexpr int nval = -1;

	using dpi_t = vector<vector<int>>;

	bool subsetSumToKMemo(size_t i, int target, const vector<int>& arr, dpi_t& dp) {
		
		if (target == 0) return true;
		if (i == 0) return arr[0] == target;

		if (dp[i][target] != nval) return dp[i][target];

		bool notTake = subsetSumToKMemo(i - 1, target, arr, dp);
		bool take = false;

		if (arr[i] <= target) take = subsetSumToKMemo(i - 1, target - arr[i], arr, dp);

		return dp[i][target] = notTake | take;
	}

	bool subsetSumToKMemo(const vector<int>& arr, int target) {

		const auto n = arr.size();
		dpi_t dp(n, vector<int>(target + 1, nval));
		return subsetSumToKMemo(n - 1, target, arr, dp);
	}

	bool subsetSumToKTab(const vector<int>& arr, int target) {
		using dp_t = vector<vector<bool>>;

		const auto n = arr.size();
		dp_t dp(n, vector<bool>(target + 1, false));
		
		for (size_t i = 0; i != n; ++i) dp[i][0] = true;
		if(arr[0] <= target) dp[0][arr[0]] = true;

		for (size_t i = 1; i != n; ++i) {
			for (int k = 1; k <= target; ++k) {
				bool notTake = dp[i - 1][k];
				bool take = false;
				if (arr[i] <= k) take = dp[i - 1][k - arr[i]];

				dp[i][k] = take || notTake;

			}
		}

		return dp[n-1][target];
	}


	bool subsetSumToK(int n, int k, const vector<int>& arr) {
		//return subsetSumToKMemo(arr, k);

		return subsetSumToKTab(arr, k);
	}

	void test() {
		cout << boolalpha << subsetSumToK(4, 5, { 4, 3, 2, 1 }) << endl;
		cout << boolalpha << subsetSumToK(5, 4, { 2, 5, 1, 6, 7 }) << endl;

		cout << boolalpha << subsetSumToK(4, 4, { 6, 1, 2, 1 }) << endl;
		cout << boolalpha << subsetSumToK(5, 6, { 1, 7, 2, 9, 10 }) << endl;

	}

}