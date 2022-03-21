// Author : AdarshGaur

class Solution {
public:
    vector<int> partitionLabels(string s) {
      vector<int> last(26, -1), ans;
      for(int i=0; i<s.size(); i++){
        last[s[i]-'a'] =  i;
      }
      for(int i=0; i<s.size();){
        int j = last[s[i]-'a'], l = 0;
        while(i<=j){
          j = max(last[s[i]-'a'], j);
          i++, l++;
        }
        ans.push_back(l);
      }
      return ans;
    }
};

