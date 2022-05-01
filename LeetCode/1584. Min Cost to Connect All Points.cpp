// Author : @AdarshGaur

struct DSU{
    vector<int> par, weight;
    DSU(int n){
        par.resize(n+1);
        weight.resize(n+1, 1);
        iota(par.begin(), par.end(), 0);
    }
    
    int find(int x){
        if(par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    
    bool Union(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        if(weight[a] > weight[b])
            swap(a, b);
        par[a] = b;
        weight[b] += weight[a];
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int, int, int>> dist;
        for(int i=0; i<points.size(); i++){
            int x = points[i][0], y = points[i][1];
            for(int j=i+1; j<points.size(); j++){
                int x1 = points[j][0], y1 = points[j][1];
                dist.push_back({abs(x-x1) + abs(y - y1), i, j});
            }
        }
        sort(dist.begin(), dist.end());
        DSU dsu(points.size());
        int cost = 0;
        for(auto [d, u, v]: dist){
            if(dsu.Union(u,v))
                cost += d;
        }
        return cost;
    }
};
