class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Set<Integer> prefixSet = new HashSet<>();
        for(int num: arr1){
            while(!prefixSet.contains(num) && num > 0){
                prefixSet.add(num);
                num /= 10;
            }
        }
        int maxPrefixLength = 0;
        for(int num: arr2){
            while(!prefixSet.contains(num) && num > 0){
                num /= 10;
            }
            if(num > 0 && maxPrefixLength < String.valueOf(num).length()){
                maxPrefixLength = String.valueOf(num).length();
            }
        }
        return maxPrefixLength;
    }
}
