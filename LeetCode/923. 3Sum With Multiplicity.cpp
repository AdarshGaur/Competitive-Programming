// Author : Adarsh Gaur

class Solution {
public:
    const int mod = 1e9 +7;
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> mp;
        for(int i: arr) mp[i]++;
        long long ans = 0;
        for(auto [a1, a2]: mp){
            for(auto [b1, b2]: mp){
                int t = target - a1 - b1;
                if(!mp.count(t)) continue;
                if(a1 == b1 and a1 == t){
                    ans += a2 * (a2-1) * (a2 - 2)/6;
                }else if(a1 == b1 and a1 != t){
                    ans += a2 * (a2-1)/2 * mp[t];
                }else if(a1 < b1 and b1 < t){
                    ans += a2 * b2 * mp[t];
                }
            }
        }
        return ans % mod;
    }
};
