// Author : @AdarshGaur

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), ans{};
        int bits[n];
        memset(bits, 0, sizeof(bits));
        for(int i=0; i<n; i++){
            for(auto& c: words[i])
                bits[i] |= (1<<(c-'a'));
            for(int j=0; j<i; j++){
                if(bits[i] & bits[j])
                    continue;
                ans = max<int>(ans, words[i].size() * words[j].size());
            }
        }
        return ans;
    }
};
