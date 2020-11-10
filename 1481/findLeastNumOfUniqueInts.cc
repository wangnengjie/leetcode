class Solution {
  public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
        unordered_map<int, int> countmap;
        countmap.reserve(arr.size());
        for (auto &num : arr) {
            countmap[num]++;
        }
        if (k == 0) {
            return countmap.size();
        }
        vector<int> its;
        its.reserve(countmap.size());
        // for(auto p = countmap.begin(); p != countmap.end(); p++){
        //     its.push_back(p);
        // }
        for (auto &p : countmap) {
            its.push_back(p.second);
        }
        sort(its.begin(), its.end());
        int pos = 0;
        while (pos < its.size()) {
            if (k >= its[pos]) {
                k -= its[pos];
                pos++;
            } else {
                break;
            }
        }
        return its.size() - pos;
    }
};