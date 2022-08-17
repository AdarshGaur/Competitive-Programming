// Author : @AdarshGaur

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int x = -1e9 -7, y = -1e9 -7, xc = 0, yc = 0;
        for(int &i: nums){
            if(x == i) xc++;
            else if(y == i) yc++;
            else if(xc == 0) x = i, xc = 1;
            else if(yc == 0) y = i, yc = 1;
            else xc--, yc--;
        }
        xc = 0, yc = 0;
        for(int &i: nums){
            xc += (i == x ? 1 : 0);
            yc += (i == y ? 1 : 0);
        }
        if(xc > nums.size()/3)
            ans.push_back(x);
        if(yc > nums.size()/3)
            ans.push_back(y);
        return ans;
    }
};
