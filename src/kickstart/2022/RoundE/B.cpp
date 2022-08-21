#include "../../../core/Common.h"
#include "bits/stdc++.h"
using namespace std;

void sandbox();

int main() {
  std::ifstream input_file;
  std::ofstream output_file;

#ifdef DEBUG
  const char* filename = "../src/kickstart/2022/RoundE/test/BTest.txt";
  bool exist = std::filesystem::exists(filename);
  if (!exist) {
    std::cout << "Couldn't find file {" << filename << "}" << std::endl;
    return 0;
  }

  input_file.open(filename);
  if (!input_file.is_open()) {
    std::cout << "Couldn't open input file." << std::endl;
    return 0;
  }
  std::cin.rdbuf(input_file.rdbuf());

#endif  // DEBUG

  // std::ios_base::sync_with_stdio(0);
  // std::cin.tie(0);
  // std::cout.tie(0);

  sandbox();

  return 0;
}

struct Comp {
  bool operator()(const pair<int, int>& left, const pair<int, int>& right) {
    return left.first < right.first;
  }
  bool operator()(const pair<int, int>& left, int right) {
    return left.first < right;
  }
  bool operator()(int left, const pair<int, int>& right) {
    return left < right.first;
  }
};

void sandbox() {
  size_t test_cases;
  cin >> test_cases;

  for (size_t csno{0}; csno != test_cases; csno++) {
    size_t N;

    cin >> N;

    vector<int> R;
    vector<pair<int, int>> cache;
    R.reserve(N);
    cache.reserve(N);

    for (size_t i{0}; i != N; i++) {
      int r;
      cin >> r;
      R.push_back(r);
      cache.emplace_back(pair<int, int>{r, i});
    }

    sort(cache.begin(), cache.end(), [](const auto& lhs, const auto& rhs) {
      return lhs.first < rhs.first;
    });

    cout << "Case #" << csno + 1 << ": ";

    for (size_t i{0}; i != N; i++) {
      const auto res =
          upper_bound(cache.begin(), cache.end(), R[i] * 2 + 1, Comp{});

      if (prev(res)->first == R[i] * 2) {
        cout << " " << prev(res)->first;
      }

      else if (prev(res)->second != i) {
        cout << " " << prev(res)->first;
      }

      else if (prev(res) != cache.begin() && prev(res, 2)->second != i) {
        cout << " " << prev(res, 2)->first;
      }

      else
        cout << " -1";
    }

    cout << endl;
  }
}

//
