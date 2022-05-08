// Author : @AdarshGaur

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(int &i : nums){
            while(!st.empty()){
                auto &last = st.back();
                if(__gcd(last, i) == 1)
                    break;
                i = i * (last / __gcd(last, i));
                st.pop_back();
            }
            st.push_back(i);
        }
        return st;
    }
};
