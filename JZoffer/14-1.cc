#include <cmath>

class Solution {
  public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int times = n / 3;
        int r = n % 3;
        int res = (int)pow(3.0, (double)times);
        if (r == 0) {
            return res;
        } else if (r == 2) {
            return res * 2;
        } else {
            return (res / 3) * 4;
        }
    }
};