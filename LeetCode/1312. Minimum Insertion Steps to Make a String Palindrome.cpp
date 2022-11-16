// Author: @AdarshGaur

class Solution {
public:
    int minInsertions(string s){
        int n = s.size();
        int cache[n+1][n+1];
        memset(cache, 0, sizeof(cache));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i] == s[n-1-j]){
                    cache[i+1][j+1] = cache[i][j] +1;
                }else{
                    cache[i+1][j+1] = max(cache[i][j+1], cache[i+1][j]);
                }
            }
        }
        return n - cache[n][n];
    }
};
