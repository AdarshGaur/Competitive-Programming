// Author : @AdarshGaur

class Solution {
public:
    
    int isPalin(string& s, int i, int j){
        while(i < j)
            if(s[i++] != s[j--])
                return 1;
        return 2;
    }
    
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<int> dp1(n+1, -1), dp2(n+1, -1);
        dp1[1]  = dp2[n] = 2;
        for(int i=0; i<n; i++){
            for(int j=0; i+j < n-1 and i-j > 0 and s[i+j] == s[i-j]; j++){
                if(dp2[i+j+1] == -1) dp2[i+j+1] = isPalin(s, i+j+1, n-1);
                if(dp1[i-j] == -1) dp1[i-j] = isPalin(s, 0, i-j-1);
                if(dp1[i-j] == 2 and dp2[i+j+1] == 2) return true;
            }
            
            for(int j=0; i+j < n-1 and i-j > 1 and s[i+j] == s[i-j-1]; j++){
                if(dp1[i-j-1] == -1) dp1[i-j-1] = isPalin(s, 0, i-j-2);
                if(dp2[i+j+1] == -1) dp2[i+j+1] = isPalin(s, i+j+1, n-1);
                if(dp1[i-j-1] == 2 and dp2[i+j+1] == 2) return true;
            }
        }
        return false;
    }
};
