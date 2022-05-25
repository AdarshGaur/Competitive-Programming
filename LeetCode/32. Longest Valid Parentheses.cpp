// Author : @AdarshGaur

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(st.empty())
                    st.push(i);
                else if(s[st.top()] == ')')
                    st.push(i);
                else
                    st.pop();
            }
        }
        if(st.empty()) return s.size();
        int ans = 0, last = s.size();
        while(!st.empty()){
            int v = st.top(); st.pop();
            ans = max(ans, last - v -1);
            last = v;
        }
        ans = max(ans, last);
        return ans;
    }
};
