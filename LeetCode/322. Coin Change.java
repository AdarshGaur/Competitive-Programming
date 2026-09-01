class Solution {
    public int coinChange(int[] coins, int amount) {
        final int INF = amount +1;
        int[] dp = new int[amount+1];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for(int i=1; i<= amount; i++){
            for(int coin: coins){
                if(i >= coin)
                    dp[i] = Math.min(dp[i], dp[i - coin] +1);
            }
        }
        return dp[amount] >= INF ? -1 : dp[amount];
    }
}
