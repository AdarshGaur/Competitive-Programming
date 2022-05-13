// Author : @AdarshGaur

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [&](vector<int> &a, vector<int> &b){
            if(a[0] == b[0])
                return a[1] >= b[1];
            return a[0] > b[0];
        });
        int mxd{}, mxa{}, ans{};
        for(int i=0; i<p.size(); ){
            int a = p[i][0], d = p[i][1];
            while(i<p.size() and p[i][0] == a){
                d = max(d, p[i][1]);
                if(mxd > p[i][1]) ans++;
                i++;
            }
            mxd = max(d, mxd);            
        }
        return ans;
    }
};
