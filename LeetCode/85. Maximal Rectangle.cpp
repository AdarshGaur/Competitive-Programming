// Author : @AdarshGaur

class Solution {
public:
    int largestRectangle(vector<int>& h){
        stack<int> st;
        int mx = 0;
        for(int i=0; i<h.size(); i++){
            if(st.empty() or (h[st.top()] <= h[i])){
                st.push(i);
            }else{
                while(!st.empty() and (h[st.top()] > h[i])){
                    int x = h[st.top()];
                    st.pop();
                    mx = max(mx, x * ( st.empty() ? i : i - st.top() -1));
                }
                st.push(i);
            }
        }
        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int mx = 0;
        vector<int> aux(matrix[0].size()+1, 0);
        for(auto &v : matrix){
            for(int i=0; i<v.size(); i++){
                aux[i] = (v[i] == '0' ? 0 : aux[i]+1);
            }
            mx = max(mx, largestRectangle(aux));
        }
        return mx;
    }
};
