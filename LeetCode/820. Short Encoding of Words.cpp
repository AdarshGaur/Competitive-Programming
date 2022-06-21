// Author : @AdarshGaur

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &w: words){
            reverse(w.begin(), w.end());
        }
        sort(words.begin(), words.end());
        int len = 0;
        for(int i=0; i<words.size()-1; i++){
            int n = words[i].size();
            if(words[i] == words[i+1].substr(0, n)) continue;
            else len += n + 1;
        }
        len += words.back().size() +1;
        return len;
    }
};
