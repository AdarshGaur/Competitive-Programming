// Author : @AdarshGaur

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> mp;
        for(auto v : nums)
            for(auto i: v)
                mp[i]++;
        vector<int> ans;
        for(auto [u,v]: mp)
            if(v == nums.size())
                ans.push_back(u);
        return ans;
    }
};
