// Author : @AdarshGaur

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.push_back(-1);
        stack<int> st;
        st.push(-1);
        int mx = 0;
        for(int i=0; i<h.size(); i++){
            if(st.top() == -1 or h[i] >= h[st.top()]){
                st.push(i);
            }else{
                int x = st.top();
                st.pop();
                mx = max(mx, h[x]*(i - st.top() - 1));
                i--;
            }
        }
        return mx;
    }
};
