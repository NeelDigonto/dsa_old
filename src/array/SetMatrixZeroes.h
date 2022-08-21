#pragma once
#include <core/Common.h>

namespace SetMatrixZeroes {

	class Solution {
	public:
		void setZeroes(vector<vector<int>>& matrix) {
			
			const auto m = matrix.size();
			const auto n = matrix[0].size();
			bool frrowzero = false, frcolzero = false;

			for (size_t row = 0; row != m; ++row) {
				for (size_t col = 0; col != n; ++col) {
					if (matrix[row][col] == 0) {
						if (row == 0) frrowzero = true;
						if (col == 0) frcolzero = true;

						matrix[row][0] = 0; // set row to 0
						matrix[0][col] = 0; // set col to 0
					}
				}
			}

			for (size_t row = 1; row != m; ++row)
				for (size_t col = 1; col != n; ++col)
					if (matrix[row][0] == 0 || matrix[0][col] == 0)
						matrix[row][col] = 0;

			if (frrowzero)
				for (size_t col = 0; col != n; ++col)
					matrix[0][col] = 0;

			if (frcolzero)
				for (size_t row = 0; row != m; ++row)
					matrix[row][0] = 0; 

		}
	};


	void test() {
		vector<vector<int>> matrix{ {1,1,1}, {1,0,1}, {1,1,1} };
		Solution{}.setZeroes(matrix);
		cout << matrix << endl;
		matrix = { {0, 1, 2, 0},{3, 4, 5, 2},{1, 3, 1, 5} };
		Solution{}.setZeroes(matrix);
		cout << matrix << endl;
	}
}