// Author : AdarshGaur

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> v;
        for(auto i=s[0]; i<=s[3]; i++){
            for(auto j=s[1]; j<=s[4]; j++){
                v.push_back(string(1,i) + string(1,j));
            }
        }
        return v;
    }
};
