// Author : @AdarshGaur

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, prev, cur;
        for(auto i: arr){
            cur = {i};
            for(auto j: prev){
                cur.insert(i|j);
            }
            for(auto j: cur){
                res.insert(j);
            }
            prev = cur;
        }
        return res.size();
    }
};
