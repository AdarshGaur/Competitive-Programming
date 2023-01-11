// Author: @AdarshGaur

class Solution {
public:
    int ans = 0;

    bool isPalin(string& a){
        int i = 0, j = a.size()-1;
        while(i < j){
            if(a[i] != a[j])
                return false;
            i++, j--;
        }
        return true;
    }

    void backtrack(const string& s, string& a, string& b, int indx){
        if(indx == s.size()){
            if(isPalin(a) and isPalin(b))
                ans = max<int>(ans, a.size() * b.size());
            return;
        }
        backtrack(s, a, b, indx+1);

        a += s[indx];
        backtrack(s, a, b, indx+1);
        a.pop_back();

        b += s[indx];
        backtrack(s, a, b, indx+1);
        b.pop_back();

        return;
    }

    int maxProduct(string s) {
        string a, b;
        backtrack(s, a, b, 0);
        return ans;
    }
};
