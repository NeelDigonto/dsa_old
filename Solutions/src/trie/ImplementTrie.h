#pragma once
#include <core/Common.h>
#include <core/Trie.h>

using namespace cds;

namespace ImplementTrie {
    class Trie {
    private:
        using CT = cds::Trie<char, 'a', 'z' + 1>;
        CT c;
    public:
        Trie() = default;

        inline void insert(string word) {
           c.Insert(begin(word), end(word));
        }

        inline bool search(string word) {
            return c.Search(begin(word), end(word));
        }

        inline bool startsWith(string prefix) {
            return c.StartsWith(begin(prefix), end(prefix));
        }
    };

    void rndString() {

    }

	void test() {
        Trie trie{};
		trie.insert("apple");
        cout << boolalpha << trie.search("apple") << endl;   // return True
		cout << boolalpha << trie.search("app") << endl;     // return False
        cout << boolalpha << trie.startsWith("app") << endl; // return True
        cout << boolalpha << trie.startsWith("bpp") << endl; // return False
        trie.insert("app");
        cout << boolalpha << trie.search("app") << endl;     // return True
	}
}