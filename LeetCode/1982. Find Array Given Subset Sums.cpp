// Author : @AdarshGaur

class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        vector<int> ans;
        while(sums.size() > 1){
            vector<int> l, r;
            int x = sums[1] - sums[0], lzero = false;
            for(int i=0, j=0; i<sums.size(); i++){
                if(sums[i] != INT_MIN){
                    lzero = lzero or (sums[i] == 0);
                    l.push_back(sums[i]);
                    r.push_back(sums[i] +x);
                    j = max(j+1, i+1);
                    while(sums[j] != sums[i] +x) j++;
                    sums[j] = INT_MIN;
                }
            }
            ans.push_back(x * (lzero ? 1 : -1));
            // sums = (lzero ? l : r);
            swap(sums, (lzero ? l : r));
        }
        return ans;
    }
};
