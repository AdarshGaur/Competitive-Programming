// Author: @AdarshGaur

class Solution {
public:
    // vector<int> circularPermutation(int n, int start) {
    //     vector<int> ans(1<<n);
    //     int r = 0;
    //     for(int i=0; i<(1<<n); i++){
    //         ans[i] = i ^ (i >> 1);
    //         if(ans[i] == start)
    //             r = i;
    //     }
    //     rotate(ans.begin(), ans.begin() + r, ans.end());
    //     return ans;
    // }

    void backtrack(vector<int>& ans, int& num, int n){
        if(n < 0){
            ans.push_back(num);
            return;
        }
        backtrack(ans, num, n-1);
        num ^= (1<<n);
        backtrack(ans, num, n-1);
    }

    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        backtrack(ans, start, n-1);
        return ans;
    }
};
