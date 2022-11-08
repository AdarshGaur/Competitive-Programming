// Author : @AdarshGaur

class Solution {
public:
    string minimizeResult(string e) {
        int plus = e.find('+'), n = e.size(), ans = INT_MAX;
        string res;
        for(int i=0; i < plus; i++){
            for(int j = plus+1; j<n; j++){
                string a = e.substr(0, i);
                string b = e.substr(i, plus - i);
                string c = e.substr(plus+1, j - plus);
                string d = e.substr(j+1);
                
                int p = a == "" ? 1 : stoi(a);
                int q = b == "" ? 1 : stoi(b);
                int r = c == "" ? 1 : stoi(c);
                int s = d == "" ? 1 : stoi(d);
                
                int t = p * (q + r) * s;
                if(t < ans){
                    ans = t;
                    res = a + "(" + b + "+" + c + ")" + d;
                }
            }
        }
        return res;
    }
};
