// Author : Adarsh Gaur

class Solution {
public:
    int search(vector<int>& a, int t) {
        int lo = 0, hi = a.size()-1;
        while(lo <= hi){
            int m = lo + (hi - lo )/2;
            if(a[m] == t){
                return m;
            }
            else if( a[m] > a[hi]){
                if(t < a[m] and t >= a[lo]){
                    hi = m - 1;
                }else{
                    lo = m + 1;
                }
            }else if(a[m] < a[lo]){
                if(t > a[m] and t <= a[hi]){
                    lo = m + 1;
                }else{
                    hi = m - 1;
                }
            }else{
                if(a[m] < t){
                    lo = m + 1;
                }else{
                    hi = m - 1;
                }
            }
        }
        return -1;
    }
};
