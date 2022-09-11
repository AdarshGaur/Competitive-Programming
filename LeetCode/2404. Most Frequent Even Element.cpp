// Author : @AdarshGaur

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        int val = 1e6, mxfreq = 0;
        for(int &i: nums){
            if(i%2 == 0){
                mp[i]++;
                if(mxfreq < mp[i] or (mxfreq == mp[i] and i < val)){
                    val = i;
                    mxfreq = mp[i];
                }
            }
        }
        return ( val == 1e6 ? -1 : val);
    }
};
