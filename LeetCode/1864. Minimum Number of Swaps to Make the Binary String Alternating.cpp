// Author : @AdarshGaur

class Solution {
public:
    int minSwaps(string s) {
        int one{}, zero{}, n = s.size();
        int a[2]{};
        for(int i=0; i<n; i++){
            one += (s[i] == '1');
            zero += (s[i] == '0');
            if(i&1){
                a[0] += (s[i] == '0');
                a[1] += (s[i] == '1');
            }
        }
        if( n%2 == 0 and one != zero) return -1;
        if(n&1){
            int mx = max(one, zero), mn = min(one, zero);
            if(mx != mn +1) return -1;
            if(mx == one) return a[1];
            return a[0];
        }
        return min(a[0], a[1]);
    }
};
