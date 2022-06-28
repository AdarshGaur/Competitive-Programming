// Author : @AdarshGaur

class Solution {
public:
    int minDeletions(string s) {
        int f[26] = {};
        for(auto &i: s){
            f[i-'a']++;
        }
        int ans = 0;
        map<int,int> mp;
        mp[f[0]] = 1;
        for(int i=1; i<26; i++){
            while(mp.find(f[i]) != mp.end() and f[i] != 0){
                ans++, f[i]--;
            }
            mp[f[i]] = 1;
        }
        return ans;
    }
};
