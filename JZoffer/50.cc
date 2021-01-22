class Solution {
  public:
    char firstUniqChar(string s) {
        if (s.empty()) {
            return ' ';
        }
        auto table = vector<int>(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int c = s.at(i) - 'a';
            if (table[c] == -1) {
                table[c] = i;
            } else if (table[c] >= 0) {
                table[c] = -2;
            }
        }
        int idx = 26, pos = s.size();
        for (int i = 0; i < table.size(); i++) {
            if (table[i] >= 0) {
                if (table[i] < pos) {
                    pos = table[i];
                    idx = i;
                }
            }
        }
        return idx == 26 ? ' ' : idx + 'a';
    }
};