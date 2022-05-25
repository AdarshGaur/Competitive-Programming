// Author : @AdarshGaur

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        if(g[0][0] == 1 or g.back().back() == 1) return 0;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<g[0].size(); j++){
                if(g[i][j] == 1){
                    g[i][j] = 0;
                    continue;
                }
                if(i==0 && j==0){
                    g[0][0] = 1;
                }else if(i == 0){
                    g[i][j] = g[i][j-1];
                }else if(j==0){
                    g[i][j] = g[i-1][j];
                }else{
                    g[i][j] = g[i][j-1] + g[i-1][j];
                }
            }
        }
        return g.back().back();
    }
};
