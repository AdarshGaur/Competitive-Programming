// Author: @AdarshGaur

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), steps=0;
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool> used(n, false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            for(int i_ = q.size(); i_>0; i_--){
                int i = q.front();
                q.pop();
                if(i == n-1) return steps;
                mp[arr[i]].push_back(i-1);
                mp[arr[i]].push_back(i+1);
                for(auto &j: mp[arr[i]]){
                    if(j >= 0 and j < n and !used[j]){
                        used[j] = true;
                        q.push(j);
                    }
                }
                mp[arr[i]].clear();
            }
            steps++;
        }
        return n-1;
    }
};

