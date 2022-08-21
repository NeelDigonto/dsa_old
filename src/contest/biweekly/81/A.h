#pragma once
#include <core/Common.h>

namespace BW81A {

	class Solution {
	public:
		int countAsterisks(string s) {
			bool doCount = true;
			size_t count = 0;

			for (auto& ch : s) {
				if (ch == '|')
					doCount = !doCount;

				if (ch == '*' && doCount)
					count++;
			}

			return count;
		}

	};

	void test() {
		cout << Solution{}.countAsterisks("l|*e*et|c**o|*de|") << endl;
		cout << Solution{}.countAsterisks("iamprogrammer") << endl;
		cout << Solution{}.countAsterisks("yo|uar|e**|b|e***au|tifu|l") << endl;
	}
}