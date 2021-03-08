class Solution {
  public:
    bool isAlienSorted(vector<string> &words, string order) {
        if (words.size() < 2) {
            return true;
        }
        auto charMap = unordered_map<char, int>();
        for (int i = 0; i < order.size(); i++) {
            charMap[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            auto &s1 = words[i];
            auto &s2 = words[i + 1];
            int minLen = min(s1.size(), s2.size());
            bool next = false;
            for (int j = 0; j < minLen; j++) {
                if (s1[j] != s2[j]) {
                    if (charMap[s1[j]] > charMap[s2[j]]) {
                        return false;
                    } else {
                        next = true;
                        break;
                    }
                }
            }
            if (next)
                continue;
            if (s1.size() > minLen) {
                return false;
            }
        }
        return true;
    }
};