// Author : @AdarshGaur

class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& tmp, int cur, int& n, int &k){
        if(tmp.size() == k){
            ans.push_back(tmp);
            return;
        }
        if(cur > n) return;

        tmp.push_back(cur);
        solve(tmp, cur+1, n, k);
        tmp.pop_back();
        solve(tmp, cur+1, n, k);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        solve(tmp, 1, n, k);
        return ans;
    }
};
