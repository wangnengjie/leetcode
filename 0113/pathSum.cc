/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        auto res = vector<vector<int>>();
        if (root == nullptr) {
            return res;
        }
        auto tmp = vector<int>();
        search(root, sum, res, tmp);
        return res;
    }

    void search(TreeNode *root, int sum, vector<vector<int>> &res,
                vector<int> &tmp) {
        if (root == nullptr) {
            return;
        }
        int nsum = sum - root->val;
        tmp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (nsum == 0) {
                res.push_back(tmp);
            }
            tmp.pop_back();
            return;
        }
        search(root->left, nsum, res, tmp);
        search(root->right, nsum, res, tmp);
        tmp.pop_back();
        return;
    }
};