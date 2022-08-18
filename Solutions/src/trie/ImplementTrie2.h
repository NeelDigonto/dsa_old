#pragma once
#include <core/Common.h>
using namespace cds;

namespace ImplementTrie2 {
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

        inline int countWordsEqualTo(string word) {
            return c.countWordsEqualTo(begin(word), end(word));
        }

        inline int countWordsStartingWith(string prefix) {
            return c.countWordsStartingWith(begin(prefix), end(prefix));
        }

        inline void erase(string word) {
            return c.erase(begin(word), end(word));
        }
    };

    void test() {
        Trie trie{};
        trie.insert("apple");               // Inserts "apple".
        trie.insert("apple");               // Inserts another "apple".
        cout << trie.countWordsEqualTo("apple") << endl;    // There are two instances of "apple" so return 2.
        cout << trie.countWordsStartingWith("app") << endl; // "app" is a prefix of "apple" so return 2.
        trie.erase("apple");                // Erases one "apple".
        cout << trie.countWordsEqualTo("apple") << endl;    // Now there is only one instance of "apple" so return 1.
        cout << trie.countWordsStartingWith("app") << endl;; // return 1
        trie.erase("apple");                // Erases "apple". Now the trie is empty.
        cout << trie.countWordsStartingWith("app") << endl; // return 0

        trie = Trie{};
        trie.insert("coding");
        trie.insert("ninja");
        cout << trie.countWordsEqualTo("coding") << endl;   
        cout << trie.countWordsStartingWith("nin") << endl;
        trie.insert("samsung");
        trie.insert("samsung");
        trie.insert("vivo");
        trie.erase("vivo");
        cout << trie.countWordsEqualTo("samsung") << endl; 
        cout << trie.countWordsEqualTo("vivo") << endl;
        cout << trie.countWordsStartingWith("vi") << endl;


        trie = Trie{};
        trie.insert("a");
        trie.insert("pa");
        cout << boolalpha <<trie.search("p") << endl;
    }
}