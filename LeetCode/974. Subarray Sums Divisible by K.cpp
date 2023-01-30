// Author: @AdarshGaur

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1;
        for(int &i: nums){
            sum = (sum + i) % k;
            sum += (sum < 0 ? k : 0);
            if(mp.find(sum) != mp.end()){
                ans += mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};
