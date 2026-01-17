class Solution {
    vector<vector<int>> ans;
public:
    void dfs(vector<int> &path, vector<vector<int>>& graph, int u, int p = -1) {

        if(u == graph.size() - 1) ans.push_back(path);
        
        for(auto &c : graph[u]) {
            if(c == p) continue;
            path.push_back(c);
            dfs(path, graph, c, u);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<int> path = {0};
        dfs(path, graph, 0);
        
        return ans;
    }
};