// Author : @AdarshGaur

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        string prefix;
        int n = products.size();
        for(auto i: searchWord){
            prefix += i;
            int j = lower_bound(products.begin(), products.end(), prefix) - products.begin();
            ans.push_back({});
            for(int k=j; k<n && k<j+3; k++){
                if(products[k].substr(0, prefix.size()) != prefix) break;
                ans.back().push_back(products[k]);
            }
        }
        return ans;
    }
};
