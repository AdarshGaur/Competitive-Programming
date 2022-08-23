// Author : @AdarshGaur

class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int u, vector<int>& path, vector<vector<int>>& ans){
        if(u == graph.size()-1){
            ans.push_back(path);
            return;
        }
        for(auto &v: graph[u]){
            path.push_back(v);
            dfs(graph, v, path, ans);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path(1, 0);
        dfs(graph, 0, path, ans);
        return ans;
    }
};
