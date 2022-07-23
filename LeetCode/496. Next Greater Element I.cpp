// Author :@AdarshGaur

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        stack<int> st;
        for(int &i: nums2){
            while(!st.empty() and st.top() < i){
                mp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans;
        for(int &i: nums1){
            ans.push_back((mp.count(i) ? mp[i] : -1));
        }
        return ans;
    }
};
