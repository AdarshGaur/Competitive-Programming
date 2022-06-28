// Author : @AdarshGaur

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ladder = 1;
        unordered_set<string> st;
        for(auto &s: wordList){
            st.insert(s);
        }
        if(st.find(endWord) == st.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int sz = q.size();
            ladder++;
            while(sz--){
                auto s = q.front(); q.pop();
                for(int i=0; i<s.size(); i++){
                    char t = s[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        s[i] = c;
                        if(s == endWord) return ladder;
                        if(st.find(s) == st.end()) continue;
                        st.erase(s);
                        q.push(s);
                    }
                    s[i] = t;
                }
            }
        }
        return 0;
    }
};
