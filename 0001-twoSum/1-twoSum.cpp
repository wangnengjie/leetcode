#include <unordered_map>
#include <vector>
//solution2
using namespace std;
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> mymap;
    vector<int> result(2);
    typedef pair<int, int> Int_pair;
    for (int i = 0; i < nums.size(); i++)
    {
      if (mymap.count(target - nums[i]))
      {
        result[0] = i;
        result[1] = mymap[target - nums[i]];
        break;
      }
      mymap.insert(Int_pair(nums[i], i));
    }
    return result;
  }
};