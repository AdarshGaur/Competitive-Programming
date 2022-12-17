// Author: @AdarshGaur

class Solution {
public:

    int dp(int target, vector<int>& cache){
        if(target == 0) return 0;
        if(cache[target] != -1) return cache[target];

        int r = int(log2(target));
        if((1<<(r+1))-1 == target)
            return cache[target] = r+1;
        
        int ans = dp((1<<(r+1))-1 - target, cache) + r+2;
        for(int i=0; i<r; i++){
            ans = min(ans, dp(target - (1<<r)+1 + (1<<i)-1, cache) + r + 2 + i);
        }
        return cache[target] = ans;
    }

    int racecar(int target) {
        vector<int> cache(target +1, -1);
        return dp(target, cache);
    }
};
