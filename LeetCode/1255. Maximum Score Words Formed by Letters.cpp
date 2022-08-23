// Author : @AdarshGaur

class Solution {
public:
    int backtrack(vector<string>& words, vector<int>& count, vector<int>& score, int indx, int cur = 0){
        if(indx == words.size()) return cur;
        
        int ans = backtrack(words, count, score, indx+1, cur);
        
        int f[26] = {};
        for(char &c: words[indx]){
            f[c-'a']++;
            if(count[c-'a'] < f[c-'a'])
                return ans;
        }
        
        int sc = 0;
        for(int i=0; i<26; i++){
            sc += f[i] * score[i];
            count[i] -= f[i];
        }
        ans = max(ans, backtrack(words, count, score, indx+1, cur + sc));
        for(int i=0; i<26; i++)
            count[i] += f[i];
        
        return ans;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0);
        for(char &c: letters)
            count[c - 'a']++;
        return backtrack(words, count, score, 0);
    }
};
