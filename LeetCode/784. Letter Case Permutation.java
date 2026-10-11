class Solution {
    List<String> allPerms = new ArrayList<>();

    public List<String> letterCasePermutation(String s) {
        allPerms.clear();
        backtrack(s.toCharArray(), "", 0);
        return allPerms;
    }

    public void backtrack(char[] s, String t, int curIdx){
        if(curIdx == s.length){
            allPerms.add(t);
            return;
        }
        char c = s[curIdx];
        if(Character.isDigit(c)){
            backtrack(s, t + c, curIdx+1);
        }else{
            backtrack(s, t + Character.toLowerCase(c), curIdx+1);

            backtrack(s, t + Character.toUpperCase(c), curIdx +1);
        }
    }
}
