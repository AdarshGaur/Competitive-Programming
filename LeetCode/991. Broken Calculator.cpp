// Author : Adarsh Gaur

class Solution {
public:
    int brokenCalc(int s, int t) {
        int a = 0;
        while(t > s){
            if(t&1){
                a++;
                t++;
            }
            t >>= 1;
            a++;
        }
        return a+(s-t);
    }
};

