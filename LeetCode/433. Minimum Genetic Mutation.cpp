// Author: @AdarshGaur

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s{bank.begin(), bank.end()};
        if(!s.count(end)) return -1;
        int cnt = 0;
        queue<string> q;
        q.push(start);
        s.insert(start);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto u = q.front();
                q.pop();
                if(u == end) return cnt;
                s.erase(u);
                for(int i=0; i<8; i++){
                    auto last = u[i];
                    u[i] = 'A';
                    if(s.count(u)) q.push(u);
                    
                    u[i] = 'C';
                    if(s.count(u)) q.push(u);
                    
                    u[i] = 'G';
                    if(s.count(u)) q.push(u);
                    
                    u[i] = 'T';
                    if(s.count(u)) q.push(u);
                    
                    u[i] = last;
                }
            }
            cnt++;
        }
        return -1;
    }
};
