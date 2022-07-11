// Author : @AdarshGaur

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i=0, n = s.size();
        while(i<n){
            while(i<n and s[i] == ' ') i++;
            string aux;
            while(i<n and s[i] != ' ')
                aux += s[i++];
            if(aux.empty()) break;
            st.push(aux);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
