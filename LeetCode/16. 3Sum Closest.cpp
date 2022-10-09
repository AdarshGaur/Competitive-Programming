// Author : @AdarshGaur

class Solution {
public:
    int threeSumClosest(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        int ans, n = A.size(), dif = 1e9;
        for(int i=0; i<n-2; i++){
            int l = i+1, r = n-1;
            while(l < r){
                int sum = A[i] + A[l] + A[r];
                
                if(sum < target) l++;
                else if(sum > target) r--;
                else return target;
                
                if(abs(target - sum) < dif){
                    ans = sum;
                    dif = abs(target - sum);
                }
            }
        }
        return ans;
    }
};
