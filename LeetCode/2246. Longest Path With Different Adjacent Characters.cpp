// Author : @AdarshGaur

class Solution {
public:
    int dfs(vector<vector<int>>& g, string& s, int cur, int& maxPath){
        int path1 = 0, path2 = 1;
        for(int v: g[cur]){
            path1 = dfs(g, s, v, maxPath);
            if(s[cur] == s[v]) path1 = 0;
            maxPath = max(maxPath, path1 + path2);
            path2 = max(path1+1, path2);
        }
        return path2;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size(), maxPath = 1;
        vector<vector<int>> g(n);
        for(int i=1; i<n; i++)
            g[parent[i]].push_back(i);
        dfs(g, s, 0, maxPath);
        return maxPath;
    }
};
