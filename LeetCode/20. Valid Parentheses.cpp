// Author : AdarshGaur

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i : s){
            if(i == ')' or i=='}' or i==']'){
                if(st.empty()) return false;
                char c = st.top();
                st.pop();
                if( (i == ')' and c!='(' ) or
                   ( i=='}' and c!='{') or
                   ( i==']' and c!= '[') ){
                    return false;
                }
            }else{
                st.push(i);
            }
        }
        return (st.empty() ? true: false);
    }
};
