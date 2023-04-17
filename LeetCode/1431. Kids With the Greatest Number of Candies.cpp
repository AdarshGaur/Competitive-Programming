// Author: @AdarshGaur

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(begin(candies), end(candies));
        vector<bool> res;
        for(auto &v: candies){
            if(v + extraCandies >= mx){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};

