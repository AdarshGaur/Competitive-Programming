// Author : Adarsh Gaur

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int lo=0, hi = n*m -1;
        while(lo <= hi){
            int m = lo + (hi-lo)/2;
            if(mat[m/n][m%n] < target) lo = m+1;
            else if(mat[m/n][m%n] > target) hi = m-1;
            else return true;
        }
        return false;
    }
};
