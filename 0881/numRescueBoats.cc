class Solution {
  public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        int l = 0, r = people.size() - 1;
        for (; l < r; res++) {
            if (people[l] + people[r] <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
        }
        return l == r ? res + 1 : res;
    }
};