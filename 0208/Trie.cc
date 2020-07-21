#include <string>
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
    bool search(string word) {
        auto *pos = this;
        for (auto &c : word) {
            int idx = c - 'a';
            if (pos->next[idx] == nullptr) {
                return false;
            }
            pos = pos->next[idx];
        }
        return pos->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto *pos = this;
        for (auto &c : prefix) {
            int idx = c - 'a';
            if (pos->next[idx] == nullptr) {
                return false;
            }
            pos = pos->next[idx];
        }
        return true;
    }
};