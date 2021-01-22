class Solution {
  public:
    bool verifyPostorder(vector<int> &postorder) {
        if (postorder.empty()) {
            return true;
        }
        return check(postorder, 0, postorder.size() - 1, postorder[postorder.size() - 1]);
    }

    bool check(vector<int> &postorder, int start, int end, int root) {
        if (end - start < 1) {
            return true;
        }
        int i = 0, j = 0;
        for (i = start; i < end; i++) {
            if (postorder[i] < root) {
                continue;
            } else {
                break;
            }
        }
        j = i;
        i--;
        for (; j < end; j++) {
            if (postorder[j] < root) {
                return false;
            }
        }
        j--;
        if (i < 0) {
            return check(postorder, i + 1, j, postorder[j]);
        }
        return check(postorder, start, i, postorder[i]) && check(postorder, i + 1, j, postorder[j]);
    }
};