class Solution {
    public int maxProduct(String s) {
        // find all palindromes 
        int all = (1 << s.length());
        int[] palindromes = new int[all];
        for(int mask = 1; mask < all; mask++){
            if(isPalindrome(mask, s)){
                palindromes[mask] = Integer.bitCount(mask);
            }
        }

        // find disjoint sets
        int maxLen = 0;
        for(int mask = 1; mask < all; mask++){
            if(palindromes[mask] == 0)
                continue;
            for(int j = mask+1; j<all; j++){
                if(palindromes[j] == 0)
                    continue;
                if((mask & j) == 0){
                    maxLen = Math.max(maxLen, palindromes[mask] * palindromes[j]);
                }
            }
        }
        return maxLen;
    }

    private boolean isPalindrome(int mask, String s){
        int left = 0, right = s.length() -1;
        while(left < right){
            while(left < right && (mask & (1 << left)) == 0){
                left++;
            }

            while(left < right && (mask & (1 << right)) == 0){
                right--;
            }

            if(left >= right)
                break;

            // check at valid pos
            if(s.charAt(left) != s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
