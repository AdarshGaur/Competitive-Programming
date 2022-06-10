// Author : @AdarshGaur

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256]={0};
        int ans = 0;
        for(int i=0, j =-1; i<s.size(); i++){
            if(freq[s[i]] == 0){
                freq[s[i]]++;
            }else{
                while(freq[s[i]] != 0)
                    freq[s[++j]]--;
                freq[s[i]]++;
            }
            ans = max(ans, i-j);
        }
        return ans;
    }
};
