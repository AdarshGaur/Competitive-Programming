// Author : @AdarshGaur

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int map[1000001] = {}, mn = INT_MAX;
        for(int i=0; i<cards.size(); i++){
            if(map[cards[i]])
                mn = min(mn, i-map[cards[i]]+2);
            map[cards[i]] = i+1;
        }
        return mn == INT_MAX ? -1 : mn;
    }
};
