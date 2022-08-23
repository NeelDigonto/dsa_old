#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <optional>
#include <stack>
#include <iostream>
#include <utility>

namespace Q394 {

    class Solution {
    public:
        std::string decodeString(std::string s) {
            std::string result = "";
            std::stack<std::pair<std::string, int>> stack;
            std::size_t number{ 0 };

            auto rp_str = [](std::string base_str, std::size_t repeat_count) {
                std::string result = base_str;
                result.reserve(result.size() * repeat_count);

                while (--repeat_count)
                    result += base_str;

                return result;
            };

            for (char& ch : s) {
                if ('a' <= ch && ch <= 'z')
                    result.push_back(ch);

                if ('0' <= ch && ch <= '9')
                    number = 10 * number + (ch - '0');

                if (ch == '[') {
                    stack.push({ result, number });
                    result = "";
                    number = 0;
                }

                result = "";
                if (ch == ']') {
                    auto [base_str, repeat_count] = stack.top();
                    stack.pop();

                    //result = rp_str(base_str, repeat_count);.

                    base_str.reserve(result.size() * repeat_count);
                    while (repeat_count--)
                        base_str += result;

                    result = base_str;
                }
            }
            return result;
        }
    };
}