class Solution {
  public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int times = n / 3;
        int r = n % 3;
        long long res = 1;
        if (r == 1) {
            times--;
            res = 4;
        } else if (r == 2) {
            res = 2;
        }
        for (int i = 0; i < times; i++) {
            res *= 3;
            res %= 1000000007;
        }
        return res;
    }
};