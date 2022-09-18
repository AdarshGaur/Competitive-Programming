// Author : @AdarshGaur

class Solution {
public:
//     int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//         int n = nums.size(), m = multipliers.size();
//         vector<vector<int>> cache(m, vector<int>(m, INT_MIN));
        
//         function<int(int, int)> dp = [&](int i, int l){
//             if(i == m) return 0;
//             if(cache[i][l] != INT_MIN) return cache[i][l];
            
//             int r = n - 1 - i +l;
//             int left = nums[l] * multipliers[i] + dp(i+1, l+1);
//             int right = nums[r] * multipliers[i] + dp(i+1, l);
//             cache[i][l] = max(left, right);
//             return cache[i][l];
//         };
//         return dp(0, 0);
//     }
        int maximumScore(vector<int>& nums, vector<int>& multipliers) {
            int n = nums.size(), m = multipliers.size();
            vector<vector<int>> cache(m+1, vector<int>(m+1, 0));
            for(int op = m-1; op>=0; op--){
                for(int l = op; l>=0; l--){
                    int r = n - 1 - op + l;
                    cache[op][l] = max(multipliers[op] * nums[l] + cache[op+1][l+1], 
                                      multipliers[op] * nums[r] + cache[op+1][l]);
                }
            }
            return cache[0][0];
        }
};
