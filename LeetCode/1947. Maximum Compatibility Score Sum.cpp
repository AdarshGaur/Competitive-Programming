// Author: @AdarshGaur

class Solution {
public:
    int ans = 0, m = 0, n = 0;
    vector<bool> availMentor;

    void backtrack(vector<vector<int>>& students, vector<vector<int>>& mentors, int cur, int indx){
        if(indx == m){
            ans = max(ans, cur);
            return;
        }
        for(int i=0; i<m; i++){
            if(availMentor[i]){
                availMentor[i] = false;
                int t = 0;
                for(int j=0; j<n; j++){
                    t += (students[indx][j] == mentors[i][j]);
                }
                backtrack(students, mentors, cur+t, indx+1);
                availMentor[i] = true;
            }
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        m = students.size(), n = students[0].size();
        availMentor.resize(m, true);
        backtrack(students, mentors, 0, 0);
        return ans;
    }
};
