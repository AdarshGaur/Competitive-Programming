// Author : @AdarshGaur

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum{}, ans{};
        int vis[10001]={};
        for(int i=0, j=0; i<nums.size(); i++){
            while(vis[nums[i]] > 0){
                vis[nums[j]]--;
                sum -= nums[j++];
            }
            vis[nums[i]]++;
            sum += nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
