// Author : @AdarshGaur

class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        int n = A.size();
        for(int i=0; i<n/2 + n%2; i++){
            for(int j=0; j<n/2; j++){
                int temp = A[i][j];
                A[i][j] = A[n-1-j][i];
                A[n-1-j][i] = A[n-1-i][n-1-j];
                A[n-1-i][n-1-j] = A[j][n-1-i];
                A[j][n-1-i] = temp;
            }
        }
    }
};
