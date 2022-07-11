// Author : @AdarshGaur

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1; i<n; i++){
            string t;
            for(int j=0; j<ans.size(); j++){
                int cnt = 1;
                while(j+1<ans.size() and ans[j] == ans[j+1])
                    cnt++, j++;
                t += to_string(cnt) + ans[j];
            }
            ans = t;
        }
        return ans;
    }
};
