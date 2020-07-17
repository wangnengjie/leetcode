#include <algorithm>
#include <string>

using namespace std;

class Solution {
  public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        return re(s1, s2, 0, 0, s1.size());
    }

    bool re(string &s1, string &s2, int l, int r, int len) {
        auto t1 = s1.substr(l, len);
        auto t2 = s2.substr(r, len);
        if (t1 == t2) {
            return true;
        }
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) {
            return false;
        }
        int mid = len / 2;
        for (int i = 1; i < len; i++) {
            bool flag = (re(s1, s2, l, r, i) && re(s1, s2, l + i, r + i, len - i)) ||
                        (re(s1, s2, l, r + len - i, i) && re(s1, s2, l + i, r, len - i));
            if (flag) {
                return true;
            }
        }
        return false;
    }
};