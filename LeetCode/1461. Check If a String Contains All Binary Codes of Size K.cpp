// Author: @AdarshGaur

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k >= s.size()) return false;
        int total = (1<<k);
        vector<bool> present(total+1, false);
        int val=0, cnt = 1;
        for(int i=0; i<k; i++){
            val = (val << 1) + (s[i] - '0');
        }
        present[val] = true;
        for(int i=k; i<(int)s.size(); i++){
            int last = (s[i-k]-'0') << (k-1);
            val = ((val - last) << 1) + (s[i]-'0');
            if(!present[val])
                cnt++;
            present[val] = true;
        }
        return cnt == (1<<k);
    }
};
