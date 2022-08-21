// Author : @AdarshGaur

class Solution {
public:
    
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curSet, int indx){
        if(indx == nums.size())
            return;
        curSet.push_back(nums[indx]);
        ans.push_back(curSet);
        backtrack(nums, ans, curSet, indx+1);
        curSet.pop_back();
        
        backtrack(nums, ans, curSet, indx+1);
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>());
        vector<int> curSet;
        backtrack(nums, ans, curSet, 0);
        return ans;
    }
};
