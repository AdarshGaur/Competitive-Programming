// Author : @AdarshGaur

class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd, even;
        string s = to_string(num);
        for(auto i: s){
            int x = i-'0';
            if(x&1)odd.push_back(x);
            else even.push_back(x);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        for(auto &i : s){
            int x = i - '0';
            if(x&1){
                i = '0' + odd.back();
                odd.pop_back();
            }else{
                i = '0' + even.back();
                even.pop_back();
            }
        }
        return stoi(s);
    }
};
