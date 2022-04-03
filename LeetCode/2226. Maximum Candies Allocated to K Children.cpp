// Author : Adarsh Gaur

class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) {
        long long lo = 1, hi = *max_element(c.begin(), c.end()), ans=0;
        while(lo <= hi){
            long long mid = lo + (hi-lo)/2, cnt=0;
            for(int i=0; i<c.size(); i++){
                cnt += c[i]/mid;
            }
            if(cnt >= k){
                ans = mid;
                lo = mid +1;
            }else{
                hi = mid -1;
            }
        }
        return ans;
    }
};

