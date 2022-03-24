// Author : Adarsh Gaur

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        for(int i=n-1; i>=0; i--){
            if(k==0)break;
            if(k <= 25){
                res[i] = 'a'+ k;
                k = 0;
            }else{
                res[i] = 'z';
                k -= 25;
            }
        }
        return res;
    }
};

