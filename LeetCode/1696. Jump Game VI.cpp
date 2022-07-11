// Author : @AdarshGaur

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dq.push_back(0);
        for(int i=1; i<nums.size(); i++){
            while(!dq.empty() and dq.front()+k < i) dq.pop_front();
            dp[i] = nums[i] + dp[dq.front()];
            while(!dq.empty() and dp[dq.back()] < dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp.back();
    }
};
