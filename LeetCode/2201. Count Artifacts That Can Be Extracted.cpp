// Author : AdarshGaur

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int mat[n][n];
        memset(mat, 0, sizeof(mat));
        int cnt=0;
        for(auto v : artifacts){
            cnt++;
            int x = v[0], y = v[1], x2 = v[2], y2 = v[3];
            for(int i = x; i<=x2; i++){
                for(int j = y; j<=y2; j++){
                    mat[i][j] = cnt;
                }
            }
        }
        for(auto v: dig){
            int x = v[0], y=v[1];
            mat[x][y] = 0;
        }
        int ans=0;
        for(auto v: artifacts){
            bool pos = true;
            int x = v[0], y = v[1], x2 = v[2], y2 = v[3];
            for(int i = x; i<=x2; i++){
                for(int j = y; j<=y2; j++){
                    if(mat[i][j] != 0){
                        pos=false;
                        break;
                    }
                }
                if(!pos)break;
            }
            if(pos){
                ans++;
            }
        }
        return ans;
    }
};
