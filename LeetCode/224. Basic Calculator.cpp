// Author: @AdarshGaur

class Solution {
public:
    int calculate(string s) {
        stack<pair<int,int>> st;
        int n = s.size(), sum = 0, sign = 1;
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                int num = 0;
                while(i < n and isdigit(s[i])){
                    num *= 10;
                    num += (s[i++]-'0');
                }
                sum += (num * sign);
                i--;
                sign = 1;
            }else if(s[i] == '('){
                st.push({sum, sign});
                sum = 0, sign = 1;
            }else if(s[i] == ')'){
                sum = st.top().first + (st.top().second * sum);
                st.pop();
            }else if(s[i] == '-'){
                sign *= -1;
            }
        }
        return sum;
    }
};
