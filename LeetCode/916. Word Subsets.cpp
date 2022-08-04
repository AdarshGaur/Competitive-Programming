// Author : @AdarshGaur

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> count(26, 0);
        for (string &b : B) {
            auto tmp = counter(b);
            for(int i = 0; i < 26; ++i)
                count[i] = max(count[i], tmp[i]);
        }
        vector<string> res;
        for (string &a : A) {
            auto tmp = counter(a);
            bool ok = true;
            for (int i = 0; i < 26; ++i)
                if (tmp[i] < count[i]){
                    ok = false;
                    break;
                }
            if(ok) res.push_back(a);
        }
        return res;
    }

    vector<int> counter(string& word) {
        vector<int> count(26);
        for (char &c : word)
            count[c - 'a']++;
        return count;
    }

};
