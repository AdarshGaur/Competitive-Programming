// Author: @AdarshGaur

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        map<int,int> mp;
        long long ans = 0, same = 0, n = nums.size();
        for(int i=0, l=0; i<n; i++){
            mp[nums[i]]++;
            same += mp[nums[i]]-1;
            while(same >= k){
                ans += (n - i);
                mp[nums[l]]--;
                same -= mp[nums[l++]];
            }
        }
        return ans;
    }
};
