class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] lastSeen = new int[128];
        Arrays.fill(lastSeen, -1);
        int maxLen = 0;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            char c = s.charAt(right);
            if(lastSeen[c] >= left){
                left = lastSeen[c] +1;
            }
            lastSeen[c] = right;
            maxLen = Math.max(maxLen, right - left +1);
        }
        return maxLen;
    }
}
