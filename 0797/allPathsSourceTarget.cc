class Solution {
  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        auto path = vector<int>();
        auto res = vector<vector<int>>();
        path.push_back(0);
        dfs(res, graph, path, 0);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<vector<int>> &graph, vector<int> &path, int pos) {
        if (pos == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        for (auto &next : graph[pos]) {
            path.push_back(next);
            dfs(res, graph, path, next);
            path.pop_back();
        }
    }
};