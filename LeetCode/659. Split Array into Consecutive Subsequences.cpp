// Author: @AdarshGaur

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> last, left;
        for(int i: nums){
            left[i]++;
            last[i] = 0;
        }
        for(int& i: nums){
            if(left[i] == 0) continue;
            left[i]--;
            if(last[i-1] > 0){
                last[i-1]--;
                last[i]++;
            }else if(left[i+1]>0 and left[i+2]>0){
                left[i+1]--;
                left[i+2]--;
                last[i+2]++;
            }else{
                return false;
            }
        }
        return true;
    }
};
