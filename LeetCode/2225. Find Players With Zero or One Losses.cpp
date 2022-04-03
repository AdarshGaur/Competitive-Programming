// Author : Adarsh Gaur

#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> win;
        map<int, int> loses;
        for(auto &a: matches){
            win.insert(a[0]);
            loses[a[1]]++;
        }
        vector<int> s;
        for(auto [u, v]: loses){
            if(v == 1) s.push_back(u);
            win.erase(u);
        }
        return {vector<int>(win.begin(), win.end()), s};
    }
};
