class Solution {
    int n, m;
    int maxCompatibility = 0;

    public int maxCompatibilitySum(int[][] students, int[][] mentors) {
        m = students.length;
        n = students[0].length;

        int[][] score = new int[m][m];
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<n; k++){
                    score[i][j] += (students[i][k] == mentors[j][k] ? 1 : 0);
                }
            }
        }

        boolean[] mentorsTaken = new boolean[m];
        backtrack(mentorsTaken, score, 0, 0);

        return maxCompatibility;
    }

    void backtrack(boolean[] mentorsTaken, int[][] score, int runningSum, int curStudent){
        if(curStudent == m){
            maxCompatibility = maxCompatibility < runningSum ? runningSum : maxCompatibility;
            return;
        }
        for(int j=0; j<m; j++){
            if(mentorsTaken[j] == true)
                continue;
            
            mentorsTaken[j] = true;
            runningSum += score[curStudent][j];

            backtrack(mentorsTaken, score, runningSum, curStudent+1);

            runningSum -= score[curStudent][j];
            mentorsTaken[j] = false;
        }
    }
}
