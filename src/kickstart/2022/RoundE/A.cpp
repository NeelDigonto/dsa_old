#include "../../../core/Common.h"
using namespace std;

void sandbox();

int main() {
  std::ifstream input_file;
  std::ofstream output_file;

#ifdef DEBUG
  const char* filename = "../src/kickstart/2022/RoundE/test/ATest.txt";
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
    size_t N;
    cin >> N;

    cout << "Case #" << csno + 1 << ": ";

    if (N <= 5) {
      cout << 1 << "\n";
      continue;
    }

    if (N % 5 == 0)
      cout << N / 5 << "\n";
    else
      cout << N / 5 + 1 << "\n";
  }

  cout << endl;
}
