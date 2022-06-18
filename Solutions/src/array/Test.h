#pragma once
#include <core/Common.h>

namespace Test {

	string foo(int input1, string input2) {
		map<char, int> cache;
		string result = "";
		int highest_removed = -1;

		for (size_t it = 0; it != input1; ++it)
			cache.insert({ input2[it], it });

		for (auto it = cache.begin(); it != cache.end(); ++it) {
			const auto pos = it->second;
			if (pos > highest_removed) {
				auto sstr = input2.substr(0, pos + 1);
				reverse(sstr.begin(), sstr.end());
				result += sstr;
				highest_removed = pos;
				input2 = input2.substr(pos + 1);
			}
		}

		result += input2;
		return result;
	}

	void test() {
		cout << foo(3, "dad") << endl;
		cout << foo(3, "cba") << endl;
	}

}