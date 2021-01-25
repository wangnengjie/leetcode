#include <queue>
#include <vector>
using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        auto res = vector<vector<int>>();
        if (root == nullptr) {
            return res;
        }
        auto q = queue<TreeNode *>();
        q.push(root);
        q.push(nullptr);
        auto temp = vector<int>();
        bool order = false;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                if (order) {
                    res.push_back(vector<int>(temp.rbegin(), temp.rend()));
                } else {
                    res.push_back(temp);
                }
                order = !order;
                if (q.empty()) {
                    break;
                }
                temp.clear();
                q.push(nullptr);
                continue;
            }
            temp.push_back(node->val);
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        return res;
    }
};