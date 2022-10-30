// Author : @AdarshGaur

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        for(int i=0; i<plantTime.size(); i++)
            v.push_back({growTime[i], plantTime[i]});
        sort(begin(v), end(v), greater<pair<int,int>>());
        int days = 0, curday = 0;
        for(auto& [g, p]: v){
            curday += p;
            days = max(days, curday + g);
        }
        return days;
    }
};
