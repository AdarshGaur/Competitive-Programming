// Author: @AdarshGaur

class Solution {
public:

    int countNodes(vector<vector<int>>& g, int& total, long long& score, int& cnt, int cur = 0, int par = -1){
        long long p = 1;
        int s = 1;
        for(auto &v: g[cur]){
            if(v == par) continue;
            int child = countNodes(g, total, score, cnt, v, cur);
            s += child;
            p *= child;
        }
        if(total != s)
            p *= (total - s);
        
        if(score < p){
            score = p;
            cnt = 1;
        }else if(score == p){
            cnt += 1;
        }
        return s;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> g(n);
        for(int i=1; i<n; i++){
            g[parents[i]].push_back(i);
            g[i].push_back(parents[i]);
        }
        long long score = 0;
        int cnt = 0;
        countNodes(g, n, score, cnt);
        return cnt;
    }
};
