#include <vector>
using std::vector;

class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int ptr = m + n - 1;
        m--;
        n--;
        while (n >= 0) {
            nums1[ptr--] = (m >= 0 && nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
        }
    }
};