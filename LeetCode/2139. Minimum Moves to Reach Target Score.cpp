// Author : @AdarshGaur

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while(maxDoubles){
            if(target == 1) break;
            if(target &1){
                moves++;
                target--;
            }else{
                moves++;
                target >>= 1;
                maxDoubles--;
            }
        }
        moves += target == 0 ? 0 : target - 1;
        return moves;
    }
};
