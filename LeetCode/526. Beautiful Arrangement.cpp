// Author : @AdarshGaur

class Solution {
public:
    int ans = 0;
    
    void backtrack(int n, vector<bool>& vis, int left){
        if(!left){
            ans += 1;
            return;
        }
        int j = n - left +1;
        for(int i=1; i<=n; i++){
            if((i % j == 0 or j % i == 0) and !vis[i]){
                vis[i] = true;
                backtrack(n, vis, left-1);
                vis[i] = false;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<bool> vis(n+1, false);
        for(int i=1; i<=n; i++){
            vis[i] = true;
            backtrack(n, vis, n-1);
            vis[i] = false;
        }
        return ans;
    }
};
