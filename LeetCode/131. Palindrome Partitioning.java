class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        backtrack(result, new ArrayList<String>(), s, 0);
        return result;
    }

    private void backtrack(List<List<String>> result, List<String> tempList, String s, int idx){
        if(idx == s.length()){
            result.add(new ArrayList(tempList));
            return;
        }
        for(int i = idx; i<s.length(); i++){
            if(isPalindrome(s, idx, i)){
                tempList.add(s.substring(idx, i+1));
                backtrack(result, tempList, s, i+1);
                tempList.removeLast();
            }
        }
    }

    private boolean isPalindrome(String s, int start, int end){
        while(start < end){
            if(s.charAt(start++) != s.charAt(end--))
                return false;
        }
        return true;
    }
}
