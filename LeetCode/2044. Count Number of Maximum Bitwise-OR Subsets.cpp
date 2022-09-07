// Author : @AdarshGaur

class Solution {
public:
    
    void solve(vector<int>& nums, int OR, int pos, int& ans, int& mx){
        if(pos == nums.size()){
            if(mx < OR){
                mx = OR;
                ans = 1;
            }else if(OR == mx){
                ans++;
            }
            return ;
        }
        
        solve(nums, OR, pos+1, ans, mx);
        solve(nums, OR|nums[pos], pos+1, ans, mx);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int ans{}, mx{};
        solve(nums, 0, 0, ans, mx);
        return ans;
    }
};
