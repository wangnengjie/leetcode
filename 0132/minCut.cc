class Solution {
  public:
    int minCut(string s) {
        auto arr = vector<vector<bool>>(s.size(), vector<bool>(s.size(), true));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                arr[i][j] = arr[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        auto dp = vector<int>(s.size(), INT_MAX);
        for (int i = 0; i < s.size(); i++) {
            if (arr[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (arr[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};