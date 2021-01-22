class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        auto charset = unordered_set<char>();
        int max = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            char c = s.at(r);
            if (charset.find(c) == charset.end()) {
                charset.insert(c);
            } else {
                max = charset.size() > max ? charset.size() : max;
                while (s.at(l) != c) {
                    charset.erase(s.at(l++));
                }
                l++;
            }
        }
        return charset.size() > max ? charset.size() : max;
    }
};