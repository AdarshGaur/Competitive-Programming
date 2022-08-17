// Author : @AdarshGaur

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        multiset<string> st;
        int l = words[0].size();
        for(int j = 0; j<l; j++){
            int last = j;
            for(auto &sub: words)
                st.insert(sub);
            for(int i=j; i+l<=s.size() and last+l <= s.size(); i += l){
                string sub = s.substr(i, l);
                while(!st.count(sub) and last < i){
                    st.insert(s.substr(last, l));
                    last += l;
                }
                if(!st.count(sub)){
                    last += l;
                    continue;
                }
                auto it = st.lower_bound(sub);
                st.erase(it);
                if(st.empty()){
                    ans.push_back(last);
                    st.insert(s.substr(last, l));
                    last += l;
                }
            }
            st.clear();
        }
        return ans;
    }
};
