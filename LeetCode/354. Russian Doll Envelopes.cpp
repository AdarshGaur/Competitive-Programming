// Author : @AdarshGaur

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), [&](vector<int>&a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> dp;
        for(auto &v: e){
            auto it = lower_bound(dp.begin(), dp.end(), v[1]);
            if(it == dp.end())
                dp.push_back(v[1]);
            else if( *it > v[1])
                *it = v[1];
        }
        return dp.size();
    }
};
