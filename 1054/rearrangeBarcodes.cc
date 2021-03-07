class Solution {
  public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes) {
        if (barcodes.size() < 2) {
            return barcodes;
        }
        auto res = vector<int>();
        auto numq = priority_queue<pair<int, int>>();
        res.reserve(barcodes.size());
        auto numMap = unordered_map<int, int>();
        for (const auto &num : barcodes) {
            numMap[num]++;
        }
        for (const auto &p : numMap) {
            numq.push({p.second, p.first});
        }
        while (true) {
            auto p1 = numq.top();
            numq.pop();
            auto p2 = numq.top();
            numq.pop();
            if (p1.first == 0 && p2.first == 0) {
                break;
            }
            if (p1.first > 0) {
                res.push_back(p1.second);
                numq.push({p1.first - 1, p1.second});
            }
            if (p2.first > 0) {
                res.push_back(p2.second);
                numq.push({p2.first - 1, p2.second});
            }
        }
        return res;
    }
};