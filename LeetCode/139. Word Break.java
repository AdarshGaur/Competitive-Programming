class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        boolean[] dp = new boolean[n+1];
        dp[0] = true;
        Set<String> reverseWords = new HashSet<>();
        for(String st: wordDict){
            reverseWords.add(new StringBuilder(st).reverse().toString());
        }
        for(int i=1; i<=n; i++){
            StringBuilder sb = new StringBuilder();
            for(int j=0; j<i; j++){
                sb.append(s.charAt(i - j-1));
                if(reverseWords.contains(sb.toString()) && dp[i-1 -j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
