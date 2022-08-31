// Author : @AdarshGaur

class Solution {
public:
    
    vector<int> count(int n){
        vector<int> freq(10, 0);
        while(n > 0){
            freq[n % 10]++;
            n /= 10;
        }
        return freq;
    }
    
    bool reorderedPowerOf2(int n){
        auto store = count(n);
        for(int i=0; i<30; i++){
            if(store == count(1 << i))
                return true;
        }
        return false;
    }
    
//     Backtracking Solution
//     int f[10] = {};
//     bool backtrack(int cur, int len){
//         if(len == 0){
//             return __builtin_popcount(cur) == 1;
//         }
//         for(int i=0; i<10; i++){
//             if(f[i]){
//                 f[i]--;
//                 if(backtrack(cur*10 +i, len-1)) return true;
//                 f[i]++;
//             }
//         }
//         return false;
//     }
    
//     bool reorderedPowerOf2(int n) {
//         int len = 0;
//         while(n > 0){
//             int x = n%10;
//             f[x]++;
//             len++;
//             n /= 10;
//         }
//         for(int i=1; i<10; i++){
//             if(f[i]){
//                 f[i]--;
//                 if(backtrack(i, len-1)) return true;
//                 f[i]++;
//             }
//         }
//         return false;
//     }
};
