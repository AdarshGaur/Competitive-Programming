// Author : @AdarshGaur

class Solution {
public:
    string pushDominoes(string d) {
        d += "R";
        char last = 'L';
        for(int i=0, lp = 0; i < d.size()-1; i++){
            while(d[i] == '.') i++;
            if(d[i] == 'L'){
                if(last == 'L'){
                    while(lp != i)
                        d[lp++] = 'L';
                }else{
                    int cur = i-1;
                    while(lp < cur){
                        d[lp++] = 'R';
                        d[cur--] = 'L';
                    }
                }
                lp = i+1, last = 'L';
            }else{
                if(last == 'R')
                    while(lp != i)
                        d[lp++] = 'R';
                last = 'R', lp = i+1;
            }
        }
        d.pop_back();
        return d;
    }
};
