// Author : @AdarshGaur

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<int,int> row, col;
        map<pair<int,int>, int> d1, d2;
        map<pair<int,int>, bool> onLamp;
        for(auto &v: lamps){
            int r = v[0], c = v[1];
            if(onLamp.count({r,c})) continue;
            onLamp[{r,c}] = true;
            row[r]++;
            col[c]++;
            int d = min(r, c);
            r -= d, c -= d;
            d1[{r,c}]++;
            r = v[0], c = v[1];
            d = min(r, n-1-c);
            r -= d, c += d;
            d2[{r,c}]++;
        }
        vector<int> ans;
        for(auto &q: queries){
            int r = q[0], c = q[1];
            // answer the query
            int illu = 0;
            if(row.count(r) and row[r]>0)
                illu = 1;
            if(col.count(c) and col[c] > 0)
                illu = 1;
            int d = min(r,c);
            r -= d, c -= d;
            if(d1.count({r,c}) and d1[{r,c}] > 0)
                illu = 1;
            r = q[0], c = q[1];
            d = min(r, n-1-c);
            r -= d, c += d;
            if(d2.count({r,c}) and d2[{r,c}] > 0)
                illu = 1;
            ans.push_back(illu);
            r = q[0], c = q[1];
            
            // turn off the lamps in the neighbourhood
            for(int i = r-1; i<=r+1; i++){
                for(int j = c-1; j<=c+1; j++){
                    if(i<0 or j<0 or i>=n or j>=n) continue;
                    if(onLamp.count({i,j}) and onLamp[{i,j}] == true){
                        onLamp[{i,j}] = false;
                        row[i]--;
                        col[j]--;
                        int a = i, b = j;
                        d = min(a, b);
                        a -= d, b -= d;
                        d1[{a,b}]--;
                        a = i, b = j;
                        d = min(a, n-1-b);
                        a -= d, b += d;
                        d2[{a,b}]--;
                    }
                }
            }
        }
        return ans;
    }
};
