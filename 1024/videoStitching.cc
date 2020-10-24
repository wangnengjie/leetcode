class Solution {
  public:
    int videoStitching(vector<vector<int>> &clips, int T) {
        auto midx = vector<int>(T, 0);
        for (auto &clip : clips) {
            if (clip[0] < T) {
                midx[clip[0]] = std::max(clip[1], midx[clip[0]]);
            }
        }
        int res = 0;
        for (int i = 0, prev = 0, limit = midx[0]; i < T; i++) {
            limit = std::max(limit, midx[i]);
            if (i == limit) {
                return -1;
            }
            if (i == prev) {
                res++;
                prev = limit;
            }
        }
        return res;
    }
};