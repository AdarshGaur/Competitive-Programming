// Author : @AdarshGaur

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int l = -1, r = -1, j = -1, maxdigit = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]-'0' > maxdigit){
                maxdigit = s[i] - '0';
                j = i;
            }else if(s[i] -'0' < maxdigit){
                l = i, r = j;
            }
        }
        if(l == -1) return num;
        swap(s[l], s[r]);
        return stoi(s);
    }
};
