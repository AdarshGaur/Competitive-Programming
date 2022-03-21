// Author : AdarshGaur

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        for(auto [u, v]: mp){
            if(v & 1) return false;
        }
        return true;
    }
};
