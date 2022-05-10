// Author : @AdarshGaur

class Solution {
public:
    vector<vector<int>> res;
    void fun(vector<int>& v, int i, int k, int n){
        if(k == 0 or i>9){
            if(n == 0 and k == 0)
                res.push_back(v);
            return;
        }
        v.push_back(i);
        fun(v, i+1, k-1, n-i);
        v.pop_back();
        fun(v, i+1, k, n);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        fun(v, 1, k, n);
        return res;
    }
};
