// Author : @AdarshGaur

class Solution {
public:
    int memo[50][50][51];
    int mod = 1e9 +7;
    
    int dp(int& n, int& m, int x, int y, int moves){
        if(x < 0 or x >= n or y < 0 or y >= m) return 1;
        if(moves == 0) return 0;
        if(memo[x][y][moves] != -1) return memo[x][y][moves];
        long ans = dp(n, m, x-1, y, moves-1) + dp(n, m, x+1, y, moves-1);
        ans += dp(n, m, x, y-1, moves-1) + dp(n, m, x, y+1, moves-1);
        memo[x][y][moves] = ans%mod;
        return memo[x][y][moves];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo, -1, sizeof(memo));
        return dp(m, n, startRow, startColumn, maxMove);
    }
};
