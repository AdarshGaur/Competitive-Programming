// Author: @AdarshGaur

class Solution {
public:
    
    int convex(vector<int>& a, vector<int>& b, vector<int>& c){
        return a[0]*(b[1]-c[1]) + b[0]*(c[1]-a[1]) + c[0]*(a[1]-b[1]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(begin(trees), end(trees), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        int k = 0;
        vector<vector<int>> ans, st;
        for(auto &t: trees){
            while(k > 1 and convex(st[k-2], st[k-1], t) < 0){
                st.pop_back();
                k--;
            }
            st.push_back(t);
            k++;
        }
        
        k = 0;
        for(int i=trees.size()-1; i>=0; i--){
            while(k > 1 and convex(ans[k-2], ans[k-1], trees[i]) < 0){
                ans.pop_back();
                k--;
            }
            ans.push_back(trees[i]);
            k++;
        }
        while(!st.empty()){
            ans.push_back(st.back());
            st.pop_back();
        }
        auto same = [](vector<int>& a, vector<int>& b){
            return a[0] == b[0] and a[1] == b[1];
        };
        sort(begin(ans), end(ans));
        ans.erase(unique(begin(ans), end(ans), same), end(ans));
        return ans;
    }
};
