// Author : @AdarshGaur

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(int &i: nums)
            mp[i]++;
        int v = -1, mx{};
        for(auto& [a, t]: mp)
            if(t > mx)
                v = a, mx = t;
        return v;
    }
};
