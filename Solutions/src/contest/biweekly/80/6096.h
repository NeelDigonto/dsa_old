#pragma once
#include <core/Common.h>

// 

namespace Q6096 {

	class Solution {
	public:
		vector<int> successfulPairs(vector<int>&& spells, vector<int>&& potions, long long success) {
			sort(potions.begin(), potions.end(), std::less<int>{});
			const size_t n = spells.size();
			vector<int> pairs(n, 0);

			for (size_t i = 0; i != n; ++i) {
				const int spell_strength = spells[i];
				const double least_req_potion = static_cast<double>(success) / spell_strength;
				auto lb = lower_bound(potions.begin(), potions.end(), least_req_potion, std::less<double>{});
				if (lb == potions.end())
					pairs[i] = 0;
				else {
					const size_t dist = distance(lb, potions.end());
					pairs[i] = dist;
				}
			}

			return pairs;
		}
	};

	void test() {
		auto result = Solution{}.successfulPairs({ 5, 1, 3 }, { 1,2,3,4,5 }, 7);
		result = Solution{}.successfulPairs({ 3, 1, 2 }, { 8,5,8 }, 16);
		
	}

}