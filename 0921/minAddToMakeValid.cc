class Solution {
  public:
    int minAddToMakeValid(string S) {
        int l = 0;
        int r = 0;
        for (auto &c : S) {
            if (c == '(') {
                l++;
            } else {
                if (l > 0) {
                    l--;
                } else {
                    r++;
                }
            }
        }
        return l + r;
    }
};