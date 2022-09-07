// Author : @AdarshGaur

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pref(1, 0);
        for(int i=0; i<arr.size(); i++)
            pref.emplace_back(pref.back() ^ arr[i]);
        
        vector<int> ans;
        for(auto &q: queries){
            int left = q[0], right = q[1];
            ans.emplace_back(pref[right+1] ^ pref[left]);
        }
        return ans;
    }
};
