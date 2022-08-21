#pragma once
#include <core/Common.h>

namespace Q6098 {

	class Solution {
	private:
		pair<int, int> helper(int n, const vector<int>& nums, long long k) {
			if (n == 0) return {0, 0};

			pair<int, int> calc = helper(n-1, nums, k);
			pair<int, int> incl = {calc.first + nums[n], calc.second + 1};
			pair<int, int> excl = { calc.first, calc.second };


			
		}
	public:
		long long countSubarrays(const vector<int>& nums, long long k) {
			helper(nums.size() - 1, nums, k);
		}
	};

	void test() {
		cout << Solution{}.countSubarrays({ 2,1,4,3,5 }, 10) << endl;

	}

}