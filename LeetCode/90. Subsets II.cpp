// Author : @AdarshGaur

class Solution {
public:
    
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curSet, int indx){
        if(indx == nums.size()){
            ans.push_back(curSet);
            return;
        }
        if(curSet.empty() or curSet.back() != nums[indx])
            backtrack(nums, ans, curSet, indx+1);
        
        curSet.push_back(nums[indx]);
        backtrack(nums, ans, curSet, indx+1);
        curSet.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curSet;
        backtrack(nums, ans, curSet, 0);
        return ans;
    }
};
