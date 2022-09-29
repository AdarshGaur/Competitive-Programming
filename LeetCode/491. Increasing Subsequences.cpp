// Author : @AdarshGaur

class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(vector<int>& nums, int i, vector<int>& t){
        if(t.size() >1)
            ans.push_back(t);
        
        map<int,int> mp;
        for(int j = i; j<nums.size(); j++){
            if(mp.count(nums[j])) continue;
            if(t.empty() or t.back() <= nums[j]){
                mp[nums[j]]++;
                t.push_back(nums[j]);
                backtrack(nums, j+1, t);
                t.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> t;
        backtrack(nums, 0, t);
        return ans;
    }
};
