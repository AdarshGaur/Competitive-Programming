// Author : @AdarshGaur

class Solution {
public:
    
//     int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
//         vector<vector<int>> mat(n, vector<int>(n, 1));
//         for(auto &z: mines){
//             mat[z[0]][z[1]] = 0;
//         }
        
//         int row[n+1][n+1][2], col[n+1][n+1][2];
//         memset(row, 0, sizeof(row));
//         memset(col, 0, sizeof(col));
        
        
//         // prefix
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(mat[i][j] == 0){
//                     row[i][j+1][0] = 0;
//                     col[i+1][j][0] = 0;
//                 }else{
//                     row[i][j+1][0] = row[i][j][0] +1;
//                     col[i+1][j][0] = col[i][j][0] +1;
//                 }
//             }            
//         }
        
//         // suffix
//         for(int i = n-1; i>=0; i--){
//             for(int j=n-1; j>=0; j--){
//                 if(mat[i][j] == 0){
//                     if(j != 0)
//                         row[i][j-1][1] = 0;
//                     if(i != 0)
//                         col[i-1][j][1] = 0;
//                 }else{
//                     if(j != 0)
//                         row[i][j-1][1] = row[i][j][1] +1;
//                     if(i != 0)
//                         col[i-1][j][1] = col[i][j][1] +1;
//                 }
//             }
//         }
        
//         int ans = 0;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(mat[i][j] == 0) continue;
//                 int r = min(row[i][j][0], row[i][j][1]);
//                 int c = min(col[i][j][0], col[i][j][1]);
//                 ans = max(ans, min(r, c)+1);
//             }
//         }
//         return ans;
//     }
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int dp[n][n];
        memset(dp, 1, sizeof(dp));
        
        for(auto &z: mines){
            dp[z[0]][z[1]] = 0;
        }
        
        
        auto f = [&](int& x, int i, int j){
            x = dp[i][j] == 0 ? 0 : x +1;
            dp[i][j] = min(dp[i][j], x);
            return ;
        };
        
        for(int i=0; i<n; i++){
            for(int j=0, k=n-1, l=0, r=0, u=0, d=0; j<n; j++, k--){
                f(l, i, j);
                f(r, i, k);
                f(u, j, i);
                f(d, k, i);
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j] != 0)
                    ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
