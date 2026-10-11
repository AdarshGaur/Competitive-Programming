class Solution {
    List<String> res = new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        backtrack(n-1, n-1, "(");
        return res;
    }

    public void backtrack(int opening, int closing, String s){
        if(opening == 0 && closing == 0){
            res.add(s + ")");
            return;
        }
        if(opening > 0){
            backtrack(opening-1, closing, s + "(");
        }
        if(closing >= opening){
            backtrack(opening, closing-1, s + ")");
        }
    }
}
