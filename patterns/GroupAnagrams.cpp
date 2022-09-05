#include "../core/Common.h"
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> registry;

    for (auto& s : strs) {
      auto identity = s;
      sort(identity.begin(), identity.end());

      registry[identity].push_back(s);
    }

    vector<vector<string>> groupedAnagrams;
    groupedAnagrams.reserve(registry.size());
    for (auto& group : registry) groupedAnagrams.push_back(move(group.second));

    return groupedAnagrams;
  }
};