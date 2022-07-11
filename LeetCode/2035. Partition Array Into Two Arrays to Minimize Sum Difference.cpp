// Author : @AdarshGaur

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<vector<int>> firstHalf(n +1), secondHalf(n +1);
        for(int i=0; i < (1 << n); i++){
            int sum = 0, sum2 = 0, cnt = 0;
            for(int j=0; j<n; j++){
                if(i & (1<<j)){
                    sum += nums[j];
                    sum2 += nums[n +j];
                    cnt++;
                }
            }
            firstHalf[cnt].push_back(sum);
            secondHalf[cnt].push_back(sum2);
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(int i=1; i<n; i++){
            sort(secondHalf[i].begin(), secondHalf[i].end());
        }
        int ans = min(abs(sum - 2*firstHalf[n][0]), abs(sum - 2*secondHalf[n][0]));
        for(int i=1; i<n; i++){
            for(int& a: firstHalf[i]){
                int b = (sum - 2*a)/2;
                auto &v = secondHalf[n-i];
                int idx = lower_bound(v.begin(), v.end(), b) - v.begin();
                if(idx < v.size())
                    ans = min(ans, abs(sum - 2*(a+v[idx])));
                if(idx != 0)
                    ans = min(ans, abs(sum - 2*(a + v[idx-1])));
            }
        }
        return ans;
    }
};
