// Author : @AdarshGaur

class Solution {
public:
    int ans = 0, n;
    
    void backtrack(map<int,int>& mp, int taken, int last){
        if(taken == n){
            ans++;
            return;
        }
        
        for(auto &[u, v]: mp){
            if(v){
                int x = floor(sqrt(u+last));
                if(x * x == u + last){
                    v--;
                    backtrack(mp, taken+1, u);
                    v++;
                }
            }
        }
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        map<int,int> mp;
        for(int &i: nums)
            mp[i]++;
        
        n = nums.size();
        for(auto &[u, v]: mp){
            v--;
            backtrack(mp, 1, u);
            v++;
        }
        return ans;
    }
};
