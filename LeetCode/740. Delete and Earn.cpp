// Author : AdarshGaur

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        int freq[10001];
        memset(freq, 0, sizeof(freq));
        for(auto i: nums){
            freq[i]++;
        }
        int last = freq[1], slast = freq[0];
        for(int i=2; i<10001; i++){
            freq[i] *= i;
            freq[i] = max(last, slast + freq[i]);
            slast = last;
            last = freq[i];
        }
        return max(last, slast);
    }
};
