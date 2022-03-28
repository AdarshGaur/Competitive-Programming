// Author : Adarsh Gaur

class Solution {
public:
    bool search(vector<int>& a, int t) {
        int lo = 0, hi = a.size()-1;
        while(lo <= hi){
            int m = (lo + hi)/2;
            if(a[m] == t) return true;
            else if(a[m] == a[lo] and a[m] == a[hi]){
                lo++, hi--;
            }else if(a[lo] <= a[m]){
                if(t < a[m] and t >= a[lo]) hi = m - 1;
                else lo = m + 1;
            }else{
                if(t > a[m] and t <= a[hi]) lo = m + 1;
                else hi = m - 1;
            }
        }
        return false;
    }
};
