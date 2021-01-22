class Solution {
  public:
    int nthUglyNumber(int n) {
        // vector<int> numlist = {1};
        auto numlist = vector<int>(n, 1);
        int ptr_2 = 0, ptr_3 = 0, ptr_5 = 0;
        for (int i = 1; i < n; i++) {
            numlist[i] = std::min({2 * numlist[ptr_2], 3 * numlist[ptr_3], 5 * numlist[ptr_5]});
            if (numlist[i] == 2 * numlist[ptr_2]) {
                ptr_2++;
            }
            if (numlist[i] == 3 * numlist[ptr_3]) {
                ptr_3++;
            }
            if (numlist[i] == 5 * numlist[ptr_5]) {
                ptr_5++;
            }
        }
        return numlist.back();
    }
};