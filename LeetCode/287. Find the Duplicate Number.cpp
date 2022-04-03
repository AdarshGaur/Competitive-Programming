// Author : Adarsh Gaur

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, ans;
        while(lo <= hi){
            int m = lo + (hi-lo)/2, cnt=0;
            for(int i : nums){
                if( i <= m) cnt++;
            }
            if(cnt > m){
                ans = m;
                hi = m -1;
            }else{
                lo = m +1;
            }
        }
        return ans;
    }
};
