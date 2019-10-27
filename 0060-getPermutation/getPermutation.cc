#include <vector>
#include <string>

using std::string;
using std::vector;

// class Solution
// {
// public:
//     string re = "";
//     int nums = 0;
//     bool flag = false;
//     string getPermutation(int n, int k)
//     {
//         vector<int> arr(n);
//         vector<bool> ok(n, false);
//         dfs(arr, ok, 0, k);
//         return re;
//     }

//     void dfs(vector<int> &arr, vector<bool> &ok, int pos, const int &target)
//     {
//         if (pos == arr.size())
//         {
//             nums++;
//             if (nums == target)
//             {
//                 flag = true;
//                 for (const auto &num : arr)
//                     re += num + '0' + 1;
//             }
//             return;
//         }
//         for (int i = 0; i < arr.size() && !flag; i++)
//         {
//             if (!ok[i])
//             {
//                 arr[pos] = i;
//                 ok[i] = true;
//                 dfs(arr, ok, pos + 1, target);
//                 ok[i] = false;
//             }
//         }
//     }
// };
