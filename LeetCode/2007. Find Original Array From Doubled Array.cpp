// Author : @AdarshGaur

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        unordered_map<int,int> mp;
        sort(changed.begin(), changed.end());
        for(auto &i: changed)
            mp[i]++;
        for(auto &i: changed){
            mp[i]--;
            if(mp[i] < 0) continue;
            if(mp.count(i*2) and mp[i*2] > 0){
                mp[i*2]--;
                ans.push_back(i);
            }else{
                return vector<int>(0);
            }
        }
        return ans;
    }
};
