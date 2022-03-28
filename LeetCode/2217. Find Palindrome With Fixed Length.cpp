// Author : Adarsh Gaur

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int l) {
        int mid = (l+1)/2;
        long long start = 1, last=9;
        for(int i=0; i<mid-1; i++){
            start *= 10;
            last *= 10;
            last += 9;
        }
        vector<long long> ans;
        for(auto x : queries){
            long long v = start + x -1;
            if( v > last){
                ans.push_back(-1);
            }else{
                string s = to_string(v);
                for(int i = mid-1 - (l%2); i>=0; i--){
                    s += s[i];
                }
                ans.push_back(stoll(s));
            }
        }
        return ans;
    }
};
