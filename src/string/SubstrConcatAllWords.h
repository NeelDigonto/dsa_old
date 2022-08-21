#pragma once
#include <core/Common.h>

namespace SubstrConcatAllWords {

    class Solution {
    private:
        void assertSubstrs() {

        }
    public:
        vector<int> findSubstring(string s, const vector<string>& words) {
            
            const auto sentence_len = s.length();
            const auto word_len = words.begin()->length();
            const auto word_count = words.size();
            const auto window_size = word_count * word_len;

            unordered_map<string, bool> word_map;
            word_map.reserve(word_count);

            for (auto el : words) word_map.insert({ el, false });

            for (size_t i = 0; i + window_size <= sentence_len; ++i) {
                //if(assertSubstrs())
            }

        }
    };

    void test() {
        cout << Solution{}.findSubstring("barfoothefoobarman", { "foo","bar" }) << endl;
        cout << Solution{}.findSubstring("wordgoodgoodgoodbestword", { "word","good","best","word" }) << endl;
        cout << Solution{}.findSubstring("barfoofoobarthefoobarman", { "bar","foo","the" }) << endl;
    }

}
