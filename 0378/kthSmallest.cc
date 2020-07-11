#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        auto heap = vector<int>();
        int g = matrix.size();
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < g; j++) {
                if (heap.size() < k) {
                    heap.push_back(matrix[i][j]);
                    push_heap(heap.begin(), heap.end());
                } else if (matrix[i][j] < heap[0]) {
                    pop_heap(heap.begin(), heap.end());
                    heap[k - 1] = matrix[i][j];
                    push_heap(heap.begin(), heap.end());
                } else {
                    g = j;
                }
            }
        }
        return heap[0];
    }
};