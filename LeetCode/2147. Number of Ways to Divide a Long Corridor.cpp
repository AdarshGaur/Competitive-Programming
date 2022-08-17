// Author : @AdarshGaur

class Solution {
public:
    int numberOfWays(string s) {
        int plants = 0, seats = 0, mod = 1e9 +7;
        long ans = 1;
        for(auto& c: s){
            if(plants){
                if(c == 'P'){
                    plants++;
                }else{
                    ans = (ans * plants) %mod;
                    plants = 0;
                    seats++;
                }
            }else if(c == 'S'){
                seats++;
                if(seats%2 == 0)
                    plants = 1;
            }
        }
        if(seats == 0 or seats &1) return 0;
        return ans;
    }
};
