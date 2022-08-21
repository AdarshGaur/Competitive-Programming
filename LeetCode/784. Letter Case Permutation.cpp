// Author : @AdarshGaur

class Solution {
public:
    const int shift = 'a' - 'A';
    
    void backtrack(vector<string>& ans, string& s, int indx){
        if(indx == s.size()){
            ans.push_back(s);
            return;
        }
        if(s[indx] >= 'a' and s[indx] <= 'z'){
            s[indx] -= shift;
            backtrack(ans, s, indx+1);
            s[indx] += shift;
            backtrack(ans, s, indx+1);
        }else if(s[indx] >= 'A' and s[indx] <= 'Z'){
            s[indx] += shift;
            backtrack(ans, s, indx+1);
            s[indx] -= shift;
            backtrack(ans, s, indx+1);
        }else{
            backtrack(ans, s, indx+1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtrack(ans, s, 0);
        return ans;
    }
};
