#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
  public:
    int characterReplacement(string s, int k) {
        auto count = vector<int>(26, 0);
        int lpos = 0, rpos = 0;
        int maxLen = 0, maxCount = 0;
        for (; rpos < s.size(); rpos++) {
            count[s[rpos] - 'A']++;
            maxCount = std::max(maxCount, count[s[rpos] - 'A']);
            while(rpos - lpos - maxCount + 1 > k) {
                count[s[lpos]-'A']--;
                lpos++;
            }
            maxLen = std::max(maxLen, rpos - lpos + 1);
        }
        return maxLen;
    }
};