// Author : AdarshGaur

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<long long> s;
        for(auto i: nums){
            s.insert(i);
        }
        s.insert(1000'000'000'000);
        long long start=1, sum=0;
        for(auto i:s){
            if(i == start){
                start++;
            }else{
                if(i - start < k){
                    sum += ((i-1 + start) * (i-start))/2;
                    k -= (i-start);
                    start = i+1;
                }else{
                    long long nth = start + k-1;
                    sum += ((start+nth) * (k)) /2;
                    return sum;
                }
            }
        }
        return -1;
    }
};
