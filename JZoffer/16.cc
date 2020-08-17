class Solution {
  public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1.0) {
            return 1;
        }
        long long k = n;
        if (n < 0) {
            x = 1 / x;
            k = -k;
        }
        return p(x, k);
    }

    double p(double &x, long long k) {
        if (k == 1) {
            return x;
        }
        double t = p(x, k >> 1);
        if (k % 2) {
            return x * t * t;
        }
        return t * t;
    }
};