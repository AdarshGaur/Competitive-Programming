// Author : @AdarshGaur

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        long n = nums.size(), ans = INT_MAX;
        vector<long> a, b(1, 0);
        for(int i=0; i<n; i++){
            if(nums[i] == 1)
                a.push_back(i);
        }
        n = a.size();
        for(int i=0; i<n; i++){
            b.push_back(b[i] + a[i]);
        }
        for(int i=0; i<n-k+1; i++){
            ans = min(ans, b[i+k] + b[i] - b[i+ k/2] - b[i + (k+1)/2]);
        }
        ans -= (k/2)*((k+1)/2);
        return ans;
    }
};
