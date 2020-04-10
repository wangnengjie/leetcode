#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
    int largestPerimeter(vector<int> &A)
    {
        std::sort(A.begin(), A.end());
        for (int i = A.size() - 1, a, b, c; i > 1; i--)
        {
            a = A[i];
            b = A[i - 1];
            c = A[i - 2];
            if (a < b + c)
                return a + b + c;
        }
        return 0;
    }
};