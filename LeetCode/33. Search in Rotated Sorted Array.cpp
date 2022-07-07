// Author : @AdarshGaur

class Solution {
public:
    int search(vector<int>& a, int t) {
        int l = 0, r = a.size()-1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(a[mid] == t) return mid;
            if(a[mid] >= a[l]){
                if(t < a[mid] and t >= a[l]) r = mid-1;
                else l = mid+1;
            }else{
                if(t <= a[r] and t > a[mid]) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};
