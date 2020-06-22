#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::vector;

// failed
//
//
//
class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        auto res = vector<int>();
        if (s.empty() || words.empty()) {
            return res;
        }
        int len = words[0].size();
        auto sublen = len * words.size();
        if (sublen > s.size() || s.empty() || words.empty()) {
            return res;
        }
        auto wordMap = std::unordered_map<string, int>();
        for (auto &word : words) {
            wordMap[word]++;
        }
        for (int i = 0; i < len; i++) {
            int left = i;
            int right = i;
            auto wordMap2 = std::unordered_map<string, int>();
            int matchCount = 0;
            for (; right <= s.size() - len;) {
                auto sub = s.substr(right, len);
                right += len;
                if (wordMap.find(sub) == wordMap.end()) {
                    wordMap2.clear();
                    matchCount = 0;
                    left = right;
                    continue;
                }
                wordMap2[sub]++;
                matchCount++;
                for (; wordMap2[sub] > wordMap[sub]; left += len, matchCount--) {
                    wordMap2[s.substr(left, len)]--;
                }
                if (matchCount == words.size()) {
                    res.push_back(left);
                }
            }
        }
        return res;
    }
};