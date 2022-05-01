// Author : @AdarshGaur

class Solution {
public:
    string f(string s){
        string st;
        for(auto i: s){
            if(i == '#' and !st.empty())
                st.pop_back();
            else if(i != '#')
                st.push_back(i);
        }
        return st;
    }
    bool backspaceCompare(string s, string t) {
        if(f(s) == f(t))
            return true;
        return false;
    }
};
