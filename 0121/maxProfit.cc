#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    // int maxProfit(vector<int> &prices) {
    //     int len = prices.size();
    //     if (len == 0) {
    //         return 0;
    //     }
    //     for (int i = len - 1; i > 0; i--) {
    //         prices[i] -= prices[i - 1];
    //     }
    //     prices[0] = 0;
    //     for (int i = 1; i < len; i++) {
    //         int v = prices[i - 1] + prices[i];
    //         prices[i] = v < 0 ? 0 : v;
    //     }
    //     int max = 0;
    //     for (int i = 1; i < len; i++) {
    //         max = std::max(max, prices[i]);
    //     }
    //     return max;
    // }
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int min = prices[0];
        prices[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            prices[i] = std::max(prices[i - 1], prices[i] - min);
            min = std::min(min, prices[i]);
        }
        return prices[prices.size() - 1];
    }
};