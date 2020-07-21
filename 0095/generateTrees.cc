#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    auto generateTrees(int n) -> vector<TreeNode *> {
        if (n == 0) {
            return vector<TreeNode *>();
        }
        return dfs(1, n);
    }

    auto dfs(int l, int r) -> vector<TreeNode *> {
        auto res = vector<TreeNode *>();
        if (l > r) {
            res.push_back(nullptr);
        } else {
            for (int i = l; i <= r; i++) {
                auto leftTree = dfs(l, i - 1);
                auto rightTree = dfs(i + 1, r);
                for (auto *lt : leftTree) {
                    for (auto *rt : rightTree) {
                        auto *root = new TreeNode(i);
                        root->left = lt;
                        root->right = rt;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};