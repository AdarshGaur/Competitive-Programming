// Author : Adarsh Gaur

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(), cost = 0;
        int a[n];
        for(int i=0; i<n; i++){
            a[i] = costs[i][1] - costs[i][0];
            cost += costs[i][0];
        }
        sort(a, a+n);
        for(int i=0; i<n/2; i++){
            cost += a[i];
        }
        return cost;
    }
};
