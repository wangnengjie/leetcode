
#include <cstddef>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        auto qe = queue<TreeNode *>();
        qe.push(root);
        qe.push(root);
        while (!qe.empty()) {
            auto *node1 = qe.front();
            qe.pop();
            auto *node2 = qe.front();
            qe.pop();
            if (node1 == NULL && node2 == NULL) {
                continue;
            }
            if ((node1 == NULL || node2 == NULL) || (node1->val != node2->val)) {
                return false;
            }
            qe.push(node1->left);
            qe.push(node2->right);
            qe.push(node1->right);
            qe.push(node2->left);
        }
        return true;
    }
};