// Author : @AdarshGaur

class Solution {
public:
    pair<int,int> d[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    bool check(vector<vector<int>>& mat){
        for(auto v: mat){
            for(auto i: v){
                if(i == 1)
                    return false;
            }
        }
        return true;
    }
    
    void flip(vector<vector<int>>& mat, int x, int y){
        if(x<0 or x>=mat.size() or y<0 or y>=mat[0].size())
            return;
        mat[x][y] ^= 1;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        if(check(mat)) return 0;
        int n = mat.size(), m = mat[0].size();
        int MAX = pow(2, m*n), ans = INT_MAX;
        for(int i=1; i<MAX; i++){
            auto grid = mat;
            int cnt = 0;
            for(int j=0; j <= m*n; j++){
                if((1<<j) & i){
                    cnt++;
                    int x = j/m, y = j%m;
                    flip(grid, x, y);
                    for(auto &[dx, dy]: d)
                        flip(grid, x+dx, y+dy);
                }
            }
            if(check(grid))
                ans = min(ans, cnt);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
