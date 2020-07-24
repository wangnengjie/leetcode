#include <cstddef>
#include <stack>
using std::stack;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
  private:
    stack<TreeNode *> s;

  public:
    BSTIterator(TreeNode *root) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    auto next() -> int {
        auto *node = s.top();
        s.pop();
        auto *pos = node->right;
        while (pos != NULL) {
            s.push(pos);
            pos = pos->left;
        }
        return node->val;
    }

    /** @return whether we have a next smallest number */
    auto hasNext() -> bool { return !s.empty(); }
};