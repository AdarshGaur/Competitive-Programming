// Author: Adarsh Gaur

class Solution {
public:
    int convert(string a){
        return stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3,2));
    }
    int convertTime(string current, string correct) {
        int dif = convert(correct) - convert(current), ans=0;
        for(auto i: {60, 15, 5, 1}){
            int cnt = dif/i;
            dif -= i*cnt;
            ans += cnt;
        }
        return ans;
    }
};
