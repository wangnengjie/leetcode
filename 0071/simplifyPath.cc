#include <string>
#include <sstream>
#include <deque>

using std::deque;
using std::string;
using std::stringstream;

class Solution
{
public:
    string simplifyPath(string path)
    {
        auto cQueue = deque<string>();
        auto input = stringstream(path);
        string temp;
        while (std::getline(input, temp, '/'))
        {
            if (temp == "." || temp == "")
                continue;
            else if (temp == "..")
                if (!cQueue.empty())
                    cQueue.pop_back();
                else
                    ;
            else
                cQueue.push_back(temp);
        }
        temp.clear();
        while (!cQueue.empty())
        {
            temp += "/" + cQueue.front();
            cQueue.pop_front();
        }
        return temp.empty() ? "/" : temp;
    }
};