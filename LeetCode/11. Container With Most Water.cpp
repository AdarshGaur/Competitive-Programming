// Author : Adarsh Gaur

class Solution {
public:
    int maxArea(vector<int>& a) {
        int i=0, j = a.size()-1, area = 0;
        while(i < j){
            if(a[i] < a[j]){
                area = max(area, (j - i)*a[i++]);
            }else{
                area = max(area, (j- i)*a[j--]);
            }
        }
        return area;
    }
};
