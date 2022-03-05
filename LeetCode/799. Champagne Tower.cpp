// Author : AdarshGaur

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double tower[query_row+2][query_row+2];
        memset(tower, 0, sizeof(tower));
        tower[0][0] = poured;
        for(int i=0; i<=query_row; i++){
            for(int j=0; j<=i; j++){
                if(tower[i][j] > 1){
                    double extra = tower[i][j] -1;
                    tower[i][j] = 1;
                    tower[i+1][j] += extra/2;
                    tower[i+1][j+1] += extra/2;
                }
            }
        }
        return tower[query_row][query_glass];
    }
};
