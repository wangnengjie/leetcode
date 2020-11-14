class Solution {
  public:
    int maxDistToClosest(vector<int> &seats) {
        int max = 0;
        int count = 0;
        int i, j;
        for (i = 0; i < seats.size() && seats[i] == 0; i++)
            ;
        for (j = seats.size() - 1; j >= 0 && seats[j] == 0; j--)
            ;
        max = std::max(i, (int)seats.size() - j - 1);
        for (int k = i + 1, c = 0; k <= j; k++) {
            if (seats[k] == 0) {
                c++;
            } else {
                count = std::max(count, c);
                c = 0;
            }
        }
        max = std::max(max, (count + 1) / 2);
        return max;
    }
};