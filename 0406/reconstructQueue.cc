class Solution {
  public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        if (people.size() < 2) {
            return people;
        }
        std::sort(people.begin(), people.end(), [](const vector<int> &p1, const vector<int> &p2) {
            if (p1[0] == p2[0]) {
                return p1[1] > p2[1];
            } else {
                return p1[0] < p2[0];
            }
        });
        vector<vector<int>> np(people.size(), vector<int>(2, -1));
        np[people[0][1]] = people[0];
        for (int i = 1; i < people.size(); i++) {
            int free = people[i][1];
            int pos = 0;
            for (; free != 0; pos++) {
                if (np[pos][0] < 0) {
                    free--;
                }
            }
            while (np[pos][0] >= 0)
                pos++;
            np[pos] = people[i];
        }
        return np;
    }
};