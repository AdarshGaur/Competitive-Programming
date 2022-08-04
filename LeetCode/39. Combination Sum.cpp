// Author : @AdarshGaur

class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& C, vector<int>& store, int i, int need){
        if(i == C.size() or need < 0) return;
        if(need == 0){
            ans.push_back(store);
            return;
        }
        
        store.push_back(C[i]);
        solve(C, store, i, need - C[i]);
        store.pop_back();
        
        solve(C, store, i+1, need);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> store;
        solve(candidates, store, 0, target);
        return ans;
    }
};
