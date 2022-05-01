// Author : @AdarshGaur

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> s, e;
        for(auto v : flowers){
            s.push_back(v[0]);
            e.push_back(v[1]);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        vector<pair<int,int>> ans;
        for(int i=0; i<persons.size(); i++){
            ans.push_back({persons[i], i});
        }
        sort(ans.begin(), ans.end());
        int i=0, j=0, n = e.size(), cnt=0;
        for(int k=0; k<ans.size(); k++){
            while(i < n and s[i] <= ans[k].first) cnt++, i++;
            while(j < n and e[j] < ans[k].first) cnt--, j++;
            ans[k].first = cnt;
        }
        sort(ans.begin(), ans.end(), [&](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        });
        vector<int> ret;
        for(auto [u,v]: ans ){
            ret.push_back(u);
        }
        return ret;
    }
};
