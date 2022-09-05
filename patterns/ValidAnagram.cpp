#include "../core/Common.h"
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<typename string::value_type, int> registry;

    for (auto& el : s) registry[el]++;

    for (auto& el : t) registry[el]--;

    for (auto& el : registry)
      if (el.second != 0) return false;

    return true;
  }
};