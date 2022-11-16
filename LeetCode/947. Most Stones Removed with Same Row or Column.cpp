// Author : @AdarshGaur

class Solution {
public:
    map<int,int> mp;
    int islands = 0;
    
    int Find(int x){
        if(!mp.count(x)){
            mp[x] = x;
            islands++;
        }
        if(mp[x] != x) mp[x] = Find(mp[x]);
        return mp[x];
    }
    
    void Union(int x,int y){
        x = Find(x), y = Find(y);
        if(x != y){
            mp[x] = y;
            islands--;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        for(auto& v: stones)
            Union(v[0], 10001 + v[1]);
        return stones.size() - islands;
    }
};
