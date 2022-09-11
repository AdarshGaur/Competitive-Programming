// Author : @AdarshGaur

class Solution {
public:
    int partitionString(string s) {
        map<int,int> mp;
        int ans = 1;
        for(int i=0; i<s.size(); i++){
            if(mp.count(s[i])){
                ans++;
                mp.clear();
            }
            mp[s[i]]++;
        }
        return ans;
    }
};
