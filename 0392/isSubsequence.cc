#include <string>
using std::string;

class Solution {
  public:
    auto isSubsequence(string s, string t) -> bool {
        auto p1 = s.begin();
        auto p2 = t.begin();
        while (p1 != s.end() && p2 != t.end()) {
            if (*p1 == *p2) {
                p1++;
            }
            p2++;
        }
        return p1 == s.end();
    }
};