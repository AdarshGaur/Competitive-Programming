// Author : @AdarshGaur

class WordFilter {
public:
    unordered_map<string, vector<int>> pref, suf;
    WordFilter(vector<string>& words) {
        for(int j=0; j<words.size(); j++){
            string s="", p="", w = words[j];
            int n = w.size();
            for(int i=0; i<n; i++){
                p += w[i];
                s += w[n-1-i];
                pref[p].push_back(j);
                suf[s].push_back(j);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        if(!pref.count(prefix)) return -1;
        if(!suf.count(suffix)) return -1;
        if(pref[prefix].size() < suf[suffix].size()){
            for(int i=pref[prefix].size()-1; i>=0; i--){
                int x = pref[prefix][i];
                auto it = lower_bound(suf[suffix].begin(), suf[suffix].end(), x) - suf[suffix].begin();
                if(it<suf[suffix].size() and suf[suffix][it] == x) return x;
            }
            return -1;
        }
        for(int i=suf[suffix].size()-1; i>=0; i--){
            int x = suf[suffix][i];
            auto it = lower_bound(pref[prefix].begin(), pref[prefix].end(), x) - pref[prefix].begin();
            if(it<pref[prefix].size() and pref[prefix][it] == x) return x;
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
