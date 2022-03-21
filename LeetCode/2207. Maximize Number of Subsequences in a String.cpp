// Author : AdarshGaur

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans = 0, n = text.size(), cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(text[i] == pattern[0]){
                if(pattern[0] == pattern[1]) ans += cnt1;
                cnt1++;
            }else if(text[i] == pattern[1]){
                ans += cnt1;
                cnt2++;
            }
        }
        return ans + max(cnt1, cnt2);
    }
};

