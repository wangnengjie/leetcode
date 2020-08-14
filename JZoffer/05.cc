class Solution {
  public:
    string replaceSpace(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == ' ') {
                s.erase(i, 1);
                s.insert(i, "%20");
                i += 2;
            }
        }
        return s;
    }
};