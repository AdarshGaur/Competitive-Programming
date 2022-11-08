// Author : @AdarshGaur

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int alphabetSize = 26, ans = 0;
        vector<vector<int>> count(alphabetSize, vector<int>(alphabetSize, 0));
        for(auto &w: words){
            count[w[0]-'a'][w[1]-'a']++;
        }
        bool middle = false;
        for(int i=0; i<alphabetSize; i++){
            if(count[i][i] % 2 == 0){
                ans += count[i][i];
            }else{
                ans += count[i][i] -1;
                middle = true;
            }
            for(int j = i +1; j<alphabetSize; j++)
                ans += 2 * min(count[i][j], count[j][i]);
        }
        ans += (middle ? 1 : 0);
        return ans<<1;
    }
};
