// Author : @AdarshGaur

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int bestPrice = shopWithoutOffer(price, needs);
        for(auto &v: special){
            subtractOffer(needs, v);
            if(noNegative(needs)){
                int discountedPrice = v.back() + shoppingOffers(price, special, needs);
                bestPrice = min(bestPrice, discountedPrice);
            }
            addOffer(needs, v);
        }
        return bestPrice;
    }
    
    int shopWithoutOffer(vector<int>& price, vector<int>& needs){
        int sum{};
        for(int i=0; i<price.size(); i++)
            sum += price[i] * needs[i];
        return sum;
    }
    
    void subtractOffer(vector<int>& needs, vector<int>& sp){
        for(int i=0; i<needs.size(); i++)
            needs[i] -= sp[i];
    }
    
    void addOffer(vector<int>& needs, vector<int>& sp){
        for(int i=0; i<needs.size(); i++)
            needs[i] += sp[i];
    }
    
    bool noNegative(vector<int>& needs){
        for(auto &i: needs)
            if(i < 0) return false;
        return true;
    }
};
