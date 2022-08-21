#include "../../../core/Common.h"
using namespace std;

void sandbox();

int main() {
  std::ifstream input_file;
  std::ofstream output_file;

#ifdef DEBUG

  const char* filename = "../src/kickstart/2022/RoundE/test/DTest.txt";
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

void sandbox() {
  size_t test_cases;
  cin >> test_cases;

  for (size_t csno{0}; csno != test_cases; csno++) {
    size_t R, C;
    cin >> R >> C;

    const size_t card_rows = 2 * R + 1;
    const size_t card_cols = 2 * C + 1;

    vector<vector<char>> card(card_rows, vector<char>());

    cout << "Case #" << csno + 1 << ": \n";
  }
}
