// Author : @AdarshGaur

class Solution {
public:
    
    void backtrack(vector<int>& ans, int cur, int n, int& k){
        if(n == 0){
            ans.push_back(cur);
        }else{
            for(char i = 0; i <= 9; i++){
                if(abs(i - cur%10) == k)
                    backtrack(ans, cur*10 +i, n-1, k);
            }
        }
        cur /= 10;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++)
            backtrack(ans, i, n-1, k);
        return ans;
    }
};
