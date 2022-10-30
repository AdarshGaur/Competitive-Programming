// Author : @AdarshGaur
class Solution {
public:
    
    void backtrack(vector<string>& arr, int indx, unordered_map<char,int>& mp, int cur, int& ans){
        if(indx == arr.size()){
            ans = max(ans, cur);
            return;
        }
        
        backtrack(arr, indx+1, mp, cur, ans);
        
        unordered_map<char, int> check;
        for(auto& c : arr[indx]){
            check[c]++;
            if(check[c] + mp[c] > 1)
                return;
        }
        
        for(auto &[c, f]: check)
            mp[c]++;
        backtrack(arr, indx+1, mp, cur+arr[indx].size(), ans);
        for(auto &[c, f]: check)
            mp[c]--;
        return;
    }
    
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> mp;
        for(auto c='a'; c<='z'; c++)
            mp[c] = 0;
        int ans = 0;
        backtrack(arr, 0, mp, 0, ans);
        return ans;
    }
};
