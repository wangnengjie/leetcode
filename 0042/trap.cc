#include <vector>
#include <stack>

using std::stack;
using std::vector;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int i = 0;
        for (; i < height.size() && height[i] == 0; i++)
            ;
        if (i == height.size())
            return 0;
        int tatal = 0, preHeight;
        stack<int> h;
        h.push(i);
        for (i += 1; i < height.size(); i++)
        {
            if (height[i] < height[h.top()])
            {
                h.push(i);
            }
            else
            {
                preHeight = 0;
                while (!h.empty() && height[i] >= height[h.top()])
                {
                    tatal += (i - h.top() - 1) * (height[h.top()] - preHeight);
                    preHeight = height[h.top()];
                    h.pop();
                }
                if (!h.empty())
                {
                    tatal += (i - h.top() - 1) * (height[i] - preHeight);
                }
                h.push(i);
            }
        }
        return tatal;
    }
};