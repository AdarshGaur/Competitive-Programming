// Author : @AdarshGaur

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int last = 0, ans = 0, id = 1e4;
        for(auto &v: logs){
            int t = v[1] - last;
            if(t > ans){
                ans = t;
                id = v[0];
            }else if(t == ans){
                id = min(id, v[0]);
            }
            last = v[1];
        }
        return id;
    }
};
