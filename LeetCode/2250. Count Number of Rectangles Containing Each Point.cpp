// Author : @AdarshGaur

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> mat(101);
        for(auto v: rectangles){
            mat[v[1]].push_back(v[0]);
        }
        for(int i=0; i<101; i++){
            sort(mat[i].begin(), mat[i].end());
        }
        vector<int> ans;
        for(auto v: points){
            int cnt = 0;
            for(int i=v[1]; i<101; i++){
                cnt += mat[i].end() - lower_bound(mat[i].begin(), mat[i].end(), v[0]);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
