// Author : @AdarshGaur

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int k = INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] < k) return true;
            while(!st.empty() and st.top() < nums[i])
                k = st.top(), st.pop();
            st.push(nums[i]);
        }
        return false;
    }
};
