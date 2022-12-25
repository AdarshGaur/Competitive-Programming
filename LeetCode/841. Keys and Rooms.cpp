// Author: @AdarshGaur

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), unlocked = 1;
        vector<bool> keyFound(n, false);
        queue<int> q;
        q.push(0);
        keyFound[0] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &v: rooms[u]){
                if(!keyFound[v]){
                    q.push(v);
                    keyFound[v] = true;
                    unlocked++;
                }
            }
        }
        return unlocked == n;
    }
};
