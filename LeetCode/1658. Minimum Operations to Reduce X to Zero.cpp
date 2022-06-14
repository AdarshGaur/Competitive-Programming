// Author : @AdarshGaur

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int need = accumulate(nums.begin(), nums.end(), -x);
        if(need == 0) return nums.size();
        if(need < 0) return -1;
        int i=0, j=0, n=nums.size(), sum=0, ans=-1;
        while(j < n){
            sum += nums[j];
            while(sum > need)
                sum -= nums[i++];
            if(need == sum) ans = max(ans, j-i+1);
            j++;
        }
        return ans == -1 ? -1 : n-ans;
    }
};
