// Author : AdarshGaur

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int i=0;
        while( i < path.size()){
            i++;
            string temp = "";
            while( i < path.size() and path[i]!='/'){
                temp += path[i++];
            }
            if(temp == "" or temp == ".") continue;
            if(temp == ".."){
                if(!st.empty()){
                    st.pop_back();
                }
            }else{
                st.push_back(temp);
            }
        }
        string ans = "";
        for(auto i : st){
            ans += "/" + i;
        }
        return (ans.size() ? ans : "/");
    }
};