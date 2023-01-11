// Author: @AdarshGaur

class Solution {
public:
    int n;
    int cache[1<<14][16];

    int dp(vector<int>&tasks, int& sessionTime, int mask, int timeLeft){
        if(mask == 0) return 0;
        if(cache[mask][timeLeft] != -1) return cache[mask][timeLeft];

        int ans = n;
        for(int i=0; i<n; i++){
            if((mask>>i) & 1){
                int newMask = mask ^ (1<<i); // off the i-th bit in mask
                if(timeLeft >= tasks[i]){
                    // continue the last session
                    ans = min(ans, dp(tasks, sessionTime, newMask, timeLeft - tasks[i]));
                }else{
                    // start a new session
                    ans = min(ans, dp(tasks, sessionTime, newMask, sessionTime - tasks[i]) +1);
                }
            }
        }
        return cache[mask][timeLeft] = ans;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        memset(cache, -1, sizeof cache);
        n = tasks.size();
        return dp(tasks, sessionTime, (1<<n)-1, 0);
    }
};
