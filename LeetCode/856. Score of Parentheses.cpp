// Author : Adarsh Gaur

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(auto c : s){
            if(c == '('){
                st.push(0);
            }else{
                int x = st.top();
                st.pop();
                if(x){
                    x *= 2;
                }else{
                    x=1;
                }
                st.top() += x;
            }
        }
        return st.top();
    }
};

