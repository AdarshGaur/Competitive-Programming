// Author : @AdarshGaur

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), mx{}, indx=0;
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> dp(n, {0, -1});
        for(int i=0; i<n; i++){
            auto v = dp[i].first;
            for(int j=i+1; j<n; j++){
                if(nums[j] % nums[i] == 0 and dp[j].first < v+1){
                    dp[j] = {v+1, i};
                }
            }
            if(mx < v){
                mx = v;
                indx = i;
            }
        }
        vector<int> ans;
        while(indx != -1){
            ans.push_back(nums[indx]);
            indx = dp[indx].second;
        }
        return ans;
    }
};
