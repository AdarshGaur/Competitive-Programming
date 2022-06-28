// Author : @AdarshGaur
class Solution {
public:
    
    bool dfs(vector<vector<int>>& g, vector<int>& vis, int cur){
        if(vis[cur] == 2) return true;
        if(vis[cur] == 1) return false;
        vis[cur] = 1;
        for(auto e: g[cur]){
            if(!dfs(g, vis, e))
                return false;
        }
        vis[cur] = 2;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> vis(numCourses, 0);
        for(auto e: prerequisites)
            g[e[1]].push_back(e[0]);
        for(int i=0; i<numCourses; i++){
            if(!vis[i])
                if(!dfs(g, vis, i))
                    return false;
        }
        return true;
    }
};
