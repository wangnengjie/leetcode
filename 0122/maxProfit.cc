#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int count = 0;
        for (int i = 0; i < prices.size();) {
            int j = i + 1;
            for (; j <= prices.size(); j++) {
                if (j == prices.size()) {
                    if (j - 1 > i) {
                        count += prices[j - 1] - prices[i];
                    }
                    break;
                }
                if (prices[j] <= prices[j - 1]) {
                    if (j - 1 > i) {
                        count += prices[j - 1] - prices[i];
                    }
                    break;
                }
            }
            i = j;
        }
        return count;
    }
};