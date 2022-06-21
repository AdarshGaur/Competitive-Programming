// Author : @AdarshGaur

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int a[26]{}, b[26]{};
        for(int i=0; i<s1.size(); i++){
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }
        bool first = false, second = false;
        int cnt1{}, cnt2{};
        for(int i=0; i<26; i++){
            cnt1 += a[i], cnt2 += b[i];
            if(cnt1 < cnt2){
                if(second) return false;
                first = true;
            }else if(cnt1 > cnt2){
                if(first) return false;
                second = true;
            }
        }
        return true;
    }
};
