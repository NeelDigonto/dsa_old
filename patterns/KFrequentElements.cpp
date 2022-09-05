#include "../core/Common.h"
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int, int> registry;

    for (auto& el : nums) registry[el]++;

    vector<pair<int, int>> arr;
    arr.reserve(registry.size());

    for (auto& el : registry) arr.push_back(el);

    sort(arr.begin(), arr.end(),
         [](auto lhs, auto rhs) { return lhs.second > rhs.second; });

    vector<int> res;
    res.reserve(k);

    for (size_t i = 0; i != k; ++i) res.push_back(arr[i].first);

    return res;
  }
};

int main() { cout << Solution{}.topKFrequent({1, 1, 1, 2, 2, 3}, 2) << endl; }