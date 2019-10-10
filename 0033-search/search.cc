#include <vector>

using std::vector;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        vector<int>::size_type left = 0;
        vector<int>::size_type right = nums.size() - 1;
        while (left <= right)
        {
            auto mid = (left + right) / 2;
            if (target == nums[mid])
                return mid;
            else if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

// class Solution
// {
// public:
//     int search(vector<int> &nums, int target)
//     {
//         if (nums.empty())
//             return -1;
//         vector<int>::size_type left = 0;
//         vector<int>::size_type right = nums.size() - 1;
//         if (target >= nums[0]) // left
//         {
//             while (left <= right)
//             {
//                 auto mid = (left + right) / 2;
//                 if (nums[mid] < target)
//                 {
//                     if (nums[mid] < nums[0])
//                         right = mid - 1;
//                     else
//                         left = mid + 1;
//                 }
//                 else if (nums[mid] > target)
//                     right = mid - 1;
//                 else
//                     return mid;
//             }
//         }
//         else // right
//         {
//             while (left <= right)
//             {
//                 auto mid = (left + right) / 2;
//                 if (nums[mid] < target)
//                     left = mid + 1;
//                 else if (nums[mid] > target)
//                 {
//                     if (nums[mid] < nums[0])
//                         right = mid - 1;
//                     else
//                         left = mid + 1;
//                 }
//                 else
//                     return mid;
//             }
//         }
//         return -1;
//     }
// };