#pragma once
#include <core/Common.h>

namespace StrongPasswordChecker2 {

	class Solution {
	public:
		bool strongPasswordCheckerII(string password) {
			const bool isBig = password.length() >= 8 ? true : false;
			bool has_lowercase = false;
			bool has_uppercase = false;
			bool has_digit = false;
			bool has_special_character = false;
			bool no_same_adj_chars = true;

			const unordered_set<char> dict{ '!','@', '#', '$',  '%', '^', '&', '*', '(', ')',  '-', '+' };

			for (auto it = password.begin(); it != password.end(); ++it) {
				if (*it >= 'a' && *it <= 'z')
					has_lowercase = true;

				if (*it >= 'A' && *it <= 'Z')
					has_uppercase = true;

				if (*it >= '0' && *it <= '9')
					has_digit = true;

				if (*it >= 'A' && *it <= 'Z')
					has_uppercase = true;

				if (dict.find(*it) != dict.end())
					has_special_character = true;

				if (next(it, 1) != password.end() && *it == *next(it, 1))
					no_same_adj_chars = false;
			}

			return isBig && has_lowercase && has_uppercase && has_digit && has_special_character && no_same_adj_chars;
			
		}
	};

	void test() {
		cout << boolalpha <<Solution{}.strongPasswordCheckerII("IloveLe3tcode!") << endl;
		cout << boolalpha << Solution{}.strongPasswordCheckerII("Me+You--IsMyDream") << endl;
		cout << boolalpha << Solution{}.strongPasswordCheckerII("1aB!") << endl;
		cout << boolalpha << Solution{}.strongPasswordCheckerII("11A!A!Aa") << endl;
	}

}