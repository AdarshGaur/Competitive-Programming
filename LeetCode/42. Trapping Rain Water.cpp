// Author: @AdarshGaur

class Solution {
public:
    int trap(vector<int>& h) {
        int water = 0;
        stack<int> st;
        for(int i=0; i<h.size(); i++){
            while(!st.empty() and h[st.top()] < h[i]){
                int v = st.top();
                st.pop();
                if(st.empty()) break;
                int bounded = min(h[st.top()], h[i]) - h[v];
                water += bounded * (i - st.top() -1);
            }
            st.push(i);
        }
        return water;
    }
};
