class Solution {
    public String minWindow(String s, String t) {
        Map<Character, Integer> targetMap = new HashMap<>();
        for(char c: t.toCharArray()){
            targetMap.put(c, targetMap.getOrDefault(c, 0)+1);
        }
        int required = targetMap.size();
        int formed = 0;

        int m = s.length();
        int l = 0, r = 0;
        int[] ans = {-1, 0, 0}; // [length, left, right];
        Map<Character, Integer> windowMap = new HashMap<>();
        while(r < m){
            char c = s.charAt(r);
            windowMap.put(c, windowMap.getOrDefault(c, 0) +1);

            if(targetMap.containsKey(c) && targetMap.get(c).intValue() == windowMap.get(c).intValue()){
                formed++;
            }

            // shrink the window
            while(formed == required && l <= r){
                char cLeft = s.charAt(l);
                windowMap.put(cLeft, windowMap.get(cLeft) -1);

                if(ans[0] == -1 || (r -l +1) < ans[0]){
                    ans[0] = r - l +1;
                    ans[1] = l;
                    ans[2] = r;
                }

                if(targetMap.containsKey(cLeft) && windowMap.get(cLeft).intValue() < targetMap.get(cLeft).intValue()){
                    formed--;
                }
                
                l++;
            }
            r++;
        }
        return (ans[0] == -1) ? "" : s.substring(ans[1], ans[2]+1);
    }
}
