// Author : @AdarshGaur

class Solution {
public:
    
    long dp(int i, int j, vector<int>& cuts, vector<vector<long>>& cache){
        if(i >= j-1) return cache[i][j] = 0;
        if(cache[i][j] != -1) return cache[i][j];
        long ans = INT_MAX;
        int p = i+1;
        for(int p= i+1; p<j; p++){
            ans = min(ans, dp(i, p, cuts, cache) + dp(p, j, cuts, cache) + cuts[j] - cuts[i]);
        }
        return cache[i][j] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        int x = cuts.size()-1;
        long cache[x+1][x+1];
        memset(cache, 0, sizeof(cache));
        for(int i=x; i>=0; i--){
            for(int j=i+2; j<=x; j++){
                long ans = INT_MAX;
                for(int k=i+1; k<j; k++){
                    ans = min(ans, cuts[j] - cuts[i] + cache[i][k] + cache[k][j]);
                }
                cache[i][j] = ans;
            }
        }
        return cache[0][x];
    }
};
