class Solution {
  public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        if (arr.size() == k) {
            return arr;
        }
        auto res = vector<int>();
        if (k == 0) {
            return res;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (res.size() < k) {
                res.push_back(arr[i]);
                push_heap(res.begin(), res.end());
            } else {
                if (res[0] > arr[i]) {
                    pop_heap(res.begin(), res.end());
                    res[k - 1] = arr[i];
                    push_heap(res.begin(), res.end());
                }
            }
        }
        return res;
    }
};