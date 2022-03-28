// Author : Adarsh Gaur

class Solution {
public:
    int minDeletion(vector<int>& arr) {
        int del = 0;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] == arr[i+1]){
                del++;
                continue;
            }
            i++;
        }
        if((arr.size() - del) %2 != 0) del++;
        return del;
    }
};
