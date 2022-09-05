#include "../core/Common.h"
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, typename vector<int>::const_iterator> registry;
    for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
           const auto complement = target - *it;
      const auto res = registry.find(complement);

      if (res != registry.end())
        return {static_cast<int>(distance(nums.cbegin(), it)),
                static_cast<int>(distance(nums.cbegin(), res->second))};

      registry.insert({*it, it});
    }
    return {};
  }
};