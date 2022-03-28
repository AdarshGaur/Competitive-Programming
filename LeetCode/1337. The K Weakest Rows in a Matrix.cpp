// Author : Adarsh Gaur

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        for(int i=0; i < mat.size(); i++){
            int sol = 0;
            for(int j=0; j<mat[i].size(); j++){
                sol += mat[i][j];
            }
            v.push_back({sol,i});
        }
        sort(v.begin(), v.end());
        vector<int> weakest;
        for(int i=0; i<k; i++){
            weakest.push_back(v[i].second);
        }
        return weakest;
    }
};
