// Author : @AdarshGaur

class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int i=0, j=n.size()-1;
        while(i<j){
            if(n[i]+n[j] == target)
                return {i+1, j+1};
            else if(n[i]+n[j] < target)
                i++;
            else
                j--;
        }
        return {-1,-1};
    }
};
