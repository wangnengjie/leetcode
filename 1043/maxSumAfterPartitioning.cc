class Solution {
  public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        auto res = vector<int>(arr.size());
        res[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int mnum = arr[i];
            for (int j = 1; j <= k; j++) {
                if (i - j < 0) {
                    mnum = max(mnum, arr[0]);
                    res[i] = max(res[i], mnum * (i + 1));
                } else {
                    mnum = max(mnum, arr[i - j + 1]);
                    res[i] = max(res[i], res[i - j] + mnum * j);
                }
            }
        }
        return res.back();
    }
};