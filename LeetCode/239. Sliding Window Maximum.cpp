// Author : @AdarshGaur

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            //pop out the left behind elements
            while(!dq.empty() && dq.front()+k-1 < i)dq.pop_front();
            
            //pop out the smaller elements before this element
            // to maintain the invariant (decreasing order)
            while(!dq.empty() && nums[dq.back()] < nums[i])dq.pop_back();
            
            //push this element (index)
            dq.push_back(i);
            
            //check for ans
            if(i >= k-1)ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
