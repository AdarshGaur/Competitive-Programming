// Author : @AdarshGaur

class Solution {
public:
    
    void backtrack(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curState, int& left, int indx){
        if(left < 0){
            return ;
        }else if(indx == candidates.size()){
            if(left == 0)
                ans.push_back(curState);
            return ;
        }else if(!curState.empty() and candidates[indx] != curState.back() and left == 0){
            ans.push_back(curState);
            return ;
        }
        
        if(curState.empty() or curState.back() != candidates[indx])
            backtrack(candidates, ans, curState, left, indx+1);
        
        left -= candidates[indx];
        curState.push_back(candidates[indx]);
        backtrack(candidates, ans, curState, left, indx+1);
        curState.pop_back();
        left += candidates[indx];
        
        return ;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curState;
        backtrack(candidates, ans, curState, target, 0);
        return ans;
    }
};
