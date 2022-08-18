#pragma once
#include <core/Common.h>

namespace PascalTraingle {

	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> triangle;
			triangle.reserve(numRows);
			triangle.emplace_back(std::vector<int>{1});
			if (numRows == 1)
				return triangle;

			for (size_t row = 1; row != numRows; ++row) {
				triangle.emplace_back(std::vector<int>(row + 1, 1));
				
				for (size_t j = 1; j != row; ++j) {
					triangle[row][j] = triangle[row - 1][j - 1] + triangle[row - 1][j];
				}
			}

			return triangle;
		}
	};

	void test() {
		cout << Solution{}.generate(5) << endl;
		cout << Solution{}.generate(1) << endl;
	}

}