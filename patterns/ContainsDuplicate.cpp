#include "../core/Common.h"
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> registry;
    for (auto& el : nums) {
      auto [pos, inserted] = registry.insert(el);
      if (!inserted) return true;
    }

    return false;
  }
};

int main() {}