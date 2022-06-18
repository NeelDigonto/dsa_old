#pragma once
#include "core/Common.h"
//Overlapping Subproblems

namespace NQueen {

	class Solution {
		static constexpr size_t npos = -1;
	public:
		bool isSafe(const vector<string>& _board, size_t _i, size_t _j) {
			
			//check the row
			for (size_t it = 0; it != _i; ++it)
				if (_board[_i][it] == 'Q') return false;

			// check upper left diagonals
			for (size_t i = _i, j = _j; i != npos, j != npos; i--, j--)
				if (_board[i][j] == 'Q') return false;
				
			// check lower left diagonals
			for (size_t i = _i, j = _j; i != _board.size(), j != npos; i--, j++)
				if (_board[i][j] == 'Q') return false;

			return true;

		}

		bool solve(const vector<string>& _board, size_t _col) {
			const auto n = _board.size();
			if (_col == n) return true;

			for(size_t col = 0; )
		}

		vector<vector<string>> solveNQueens(int n) {
			vector<vector<string
			return ;
		}
	};

	void test() {
		//Sandbox<int>::tests();
		const auto solution = Solution{}.solveNQueens(4); 
		// { {".Q..", "...Q", "Q...", "..Q."}, { "..Q.", "Q...", "...Q", ".Q.." } };
	}

}

