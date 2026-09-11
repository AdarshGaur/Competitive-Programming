class Solution {
    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        for(int i=s.length()-1; i>=0; i--){
            if(i == s.length() -1){
                dp[i] = (s.charAt(i) == '0') ? 0 : 1;
            }else if(i == s.length()-2){
                if(s.charAt(i) == '0'){
                    dp[i] = 0;
                }else if(s.charAt(i) == '1'){
                    dp[i] = dp[i+1] +1;
                }else if(s.charAt(i) == '2'){
                    dp[i] = s.charAt(i+1) < '7' ? dp[i+1] +1 : dp[i+1];
                }else{
                    dp[i] = dp[i+1];
                }
            }else{
                if(s.charAt(i) == '0'){
                    dp[i] = 0;
                }else if(s.charAt(i) == '1'){
                    dp[i] = dp[i+2] + dp[i+1];
                }else if(s.charAt(i) == '2'){
                    dp[i] = s.charAt(i+1) < '7' ? dp[i+1] + dp[i+2] : dp[i+1];
                }else{
                    dp[i] = dp[i+1];
                }
            }
        }
        return dp[0];
    }
}

