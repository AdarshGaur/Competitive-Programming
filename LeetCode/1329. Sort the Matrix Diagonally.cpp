// Author : @AdarshGaur

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      int n = mat.size(), m = mat[0].size();
      for(int i=0; i<n; i++){
        priority_queue<int> t;
        int x = i, y = 0;
        while(x<n and y<m)
          t.push(mat[x++][y++]);
        while(!t.empty()){
          mat[--x][--y] = t.top();
          t.pop();
        }
      }
      
      for(int i=1; i<m; i++){
        priority_queue<int> t;
        int x = 0, y = i;
        while(x<n and y<m)
          t.push(mat[x++][y++]);
        while(!t.empty()){
          mat[--x][--y] = t.top();
          t.pop();
        }
      }
      
      return mat;
    }
};
