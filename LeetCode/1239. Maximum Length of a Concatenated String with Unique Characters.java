class Solution {
    int maxLen = 0;

    public int maxLength(List<String> arr) {
        List<Integer> masks = new ArrayList<>();
        for(String s: arr){
            boolean isValid = true;
            int mask = 0;
            for(char c: s.toCharArray()){
                if((mask & (1<<(c-'a'))) != 0){
                    isValid = false;
                    break;
                }
                mask |= (1<<(c-'a'));
            }
            if(isValid){
                masks.add(mask);
            }
        }
        backtrack(masks, 0, 0);
        return maxLen;
    }

    private void backtrack(List<Integer> masks, int mask, int start){
        maxLen = Math.max(maxLen, Integer.bitCount(mask));
        if(start == masks.size()){
            return;
        }
        for(int i=start; i<masks.size(); i++){
            if((mask & masks.get(i)) == 0){
                backtrack(masks, mask | masks.get(i), i+1);
            }
        }
        return;
    }
}
