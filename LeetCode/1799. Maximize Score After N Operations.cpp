// Author: @AdarshGaur

class Solution {
public:
    int n, ans = 0;
    int gcd[14][14] = {};
    int cache[1<<14] = {};

    int _gcd(vector<int>& a, int x, int y){
        if(gcd[x][y] != 0)
            return gcd[x][y];
        return gcd[x][y] = __gcd(a[x], a[y]);
    }

    int dp(vector<int>& nums, int op, int mask){
        if(op > n/2) return 0;
        if(cache[mask] != 0)
            return cache[mask];
        
        for(int i=0; i<n; i++){
            if((mask>>i) & 1) continue;
            for(int j=i+1; j<n; j++){
                if((mask>>j)&1) continue;
                int newMask = (1<<i) | (1<<j) | mask;
                int score = op * _gcd(nums, i, j) + dp(nums, op+1, newMask);
                cache[mask] = max(cache[mask], score);
            }
        }
        return cache[mask];
    }

    int maxScore(vector<int>& nums) {
        n = nums.size();
        return dp(nums, 1, 0);
    }
};
