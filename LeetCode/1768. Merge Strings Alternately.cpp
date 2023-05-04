// Author: @AdarshGaur

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        for(int i=0; i<max<int>(word1.size(), word2.size()); i++){
            if(i < word1.size())
                s += word1[i];
            if(i < word2.size())
                s += word2[i];
        }
        return s;
    }
};

