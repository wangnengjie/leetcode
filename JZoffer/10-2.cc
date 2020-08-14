class Solution {
  public:
    int numWays(int n) {
        if (n <= 1) {
            return 1;
        }
        int x1 = 1, x2 = 1;
        for (int i = 1; i < n; i++) {
            x2 += x1;
            x1 = x2 - x1;
            x2 %= 1000000007;
        }
        return x2;
    }
};