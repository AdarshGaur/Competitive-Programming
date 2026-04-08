class Solution {
    public int maxProductPath(int[][] grid) {
        final int mod = 1_000_000_007;
        long[][][] dp = new long[grid.length][grid[0].length][2];
        // dp[i][j][0] holds positive values
        // dp[i][j][1] holds negative values
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(j == 0 && i == 0){
                    dp[i][j][0] = grid[i][j];
                    dp[i][j][1] = grid[i][j];
                } else if(i == 0){
                    dp[i][j][0] = dp[i][j-1][0] * grid[i][j];
                    dp[i][j][1] = dp[i][j][0];
                } else if(j == 0){
                    dp[i][j][0] = dp[i-1][j][0] * grid[i][j];
                    dp[i][j][1] = dp[i][j][0];
                }else{
                    long lastMaxPos = Math.max(dp[i-1][j][0], dp[i][j-1][0]);
                    long lastMaxNeg = Math.min(dp[i-1][j][1], dp[i][j-1][1]);
                    if(grid[i][j] < 0){
                        dp[i][j][0] = (lastMaxNeg * grid[i][j]);
                        dp[i][j][1] = (lastMaxPos * grid[i][j]);
                    }else{
                        dp[i][j][0] = (lastMaxPos * grid[i][j]);
                        dp[i][j][1] = (lastMaxNeg * grid[i][j]);
                    }
                }
            }
        }
        if(dp[grid.length -1][grid[0].length -1][0] >= 0){
            return (int)(dp[grid.length -1][grid[0].length -1][0] % mod);
        }
        return -1;
    }
}

