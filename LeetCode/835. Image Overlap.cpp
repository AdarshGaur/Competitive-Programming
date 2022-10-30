// Author: @AdarshGaur

class Solution {
public:
    
    int check(vector<vector<int>>& img1, vector<vector<int>>& img2, int rowShift, int colShift){
        int n = img1.size();
        int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i+rowShift < n and j+colShift < n)
                    sum1 += img1[i][j] & img2[i+rowShift][j+colShift];
                if(i-rowShift >= 0 and j+colShift < n)
                    sum2 += img1[i][j] & img2[i-rowShift][j+colShift];
                if(i+rowShift < n and j-colShift >= 0)
                    sum3 += img1[i][j] & img2[i+rowShift][j-colShift];
                if(i - rowShift >=0 and j - colShift >=0)
                    sum4 += img1[i][j] & img2[i-rowShift][j-colShift];
            }
        }
        return max({sum1, sum2, sum3, sum4});
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, check(img1, img2, i, j));
            }
        }
        return ans;
    }
};
