// Author : @AdarshGaur

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        st.push({'a', 0});
        for(auto i : s){
            auto &[c, f] = st.top();
            if(c == i){
                f++;
                if(f == k)
                    st.pop();
            }else{
                st.push({i, 1});
            }
        }
        string ans = "";
        while(!st.empty()){
            auto &[c, f] = st.top();
            ans += string(f, c);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
