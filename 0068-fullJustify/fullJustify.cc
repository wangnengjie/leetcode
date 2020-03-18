#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> re;
        for (unsigned int length = 0, i = 0, j = 0; true; length = 0) {
            while (j < words.size() && length + words[j].size() <= maxWidth) {
                length += 1 + words[j].size();
                j++;
            }
            string temp;
            if (j == words.size() || j - i == 1) {
                temp += words[i++];
                for (; i < j; i++) {
                    temp += " " + words[i];
                }
                unsigned int l = temp.size();
                for (int k = 0; k < maxWidth - l; k++) {
                    temp += " ";
                }
                re.push_back(temp);
                if (j == words.size()) {
                    break;
                }
            } else {
                unsigned int wLength = 0;
                for (auto beg = words.begin() + i; beg != words.begin() + j;
                     beg++) {
                    wLength += beg->size();
                }
                unsigned int white = maxWidth - wLength;
                unsigned int per = white / (j - i - 1);
                unsigned int more = white - per * (j - i - 1);
                temp += words[i++];
                for (; i < j; i++) {
                    for (int k = 0; k < per; k++) {
                        temp += " ";
                    }
                    if (more > 0) {
                        temp += " " + words[i];
                        more--;
                    } else {
                        temp += words[i];
                    }
                }
                re.push_back(temp);
            }
        }
        return re;
    }
};