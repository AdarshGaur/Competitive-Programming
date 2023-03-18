// Author: @AdarshGaur

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, window = 0, a = -1, b = -1, a_ = 0;
        for(int &i: fruits){
            if(i == a){
                window += 1;
                a_ += 1;
            }else{
                if(i == b) window += 1;
                else window = a_ + 1;
                a_ = 1;
                b = a;
                a = i;
            }
            ans = max(ans, window);
        }
        return ans;
    }
};
