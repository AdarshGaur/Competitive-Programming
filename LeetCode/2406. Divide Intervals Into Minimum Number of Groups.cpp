// Author: @AdarshGaur

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        multiset<pair<int,int>> s;
        for(auto &v: intervals){
            s.insert({v[0], v[1]});
        }
        int grps= 0;
        while(!s.empty()){
            grps++;
            int cur = (*s.begin()).second;
            s.erase(s.begin());
            auto it = s.lower_bound({cur+1, 0});
            while(it != s.end()){
                cur = (*it).second;
                s.erase(it);
                it = s.lower_bound({cur+1, 0});
            }
        }
        return grps;
    }
};
