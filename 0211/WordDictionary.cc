#include <string>
#include <utility>
using std::string;

class Trie {
  private:
    bool isWord;
    Trie *next[26]{};

  public:
    /** Initialize your data structure here. */
    Trie() {
        isWord = false;
        for (auto &i : next) {
            i = nullptr;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto *pos = this;
        for (auto &c : word) {
            int idx = c - 'a';
            if (pos->next[idx] == nullptr) {
                pos->next[idx] = new Trie();
            }
            pos = pos->next[idx];
        }
        pos->isWord = true;
    }

    /** Returns if the word is in the trie. */
    auto search(string word) -> bool {
        auto *pos = this;
        for (int i = 0; i < word.size(); i++) {
            char &c = word.at(i);
            if (c == '.') {
                for (auto &j : pos->next) {
                    if (j == nullptr) {
                        continue;
                    }
                    auto res = j->search(word.substr(i + 1));
                    if (res) {
                        return true;
                    }
                }
                return false;
            }
            int idx = c - 'a';
            if (pos->next[idx] == nullptr) {
                return false;
            }
            pos = pos->next[idx];
        }
        return pos->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    auto startsWith(string prefix) -> bool {
        auto *pos = this;
        for (int i = 0; i < prefix.size(); i++) {
            char &c = prefix.at(i);
            if (c == '.') {
                for (auto &j : pos->next) {
                    if (j == nullptr) {
                        continue;
                    }
                    auto res = j->search(prefix.substr(i + 1));
                    if (res) {
                        return true;
                    }
                }
                return false;
            }
            int idx = c - 'a';
            if (pos->next[idx] == nullptr) {
                return false;
            }
            pos = pos->next[idx];
        }
        return true;
    }
};

class WordDictionary {
  private:
    Trie trie;

  public:
    /** Initialize your data structure here. */
    WordDictionary() { trie = Trie(); }

    /** Adds a word into the data structure. */
    void addWord(string word) { trie.insert(std::move(word)); }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one
     * letter. */
    auto search(string word) -> bool { return trie.search(std::move(word)); }
};
