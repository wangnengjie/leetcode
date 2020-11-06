class Solution {
  public:
    vector<int> sortByBits(vector<int> &arr) {
        vector<int> res(arr.size());
        vector<pair<int, int>> mm(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            mm[i].first = countBit(arr[i]);
            mm[i].second = arr[i];
        }
        sort(mm.begin(), mm.end());
        for (int i = 0; i < arr.size(); i++) {
            res[i] = mm[i].second;
        }
        return res;
    }

    int countBit(int num) {
        int count = 0;
        while (num) {
            num &= num - 1;
            count++;
        }
        return count;
    }
};