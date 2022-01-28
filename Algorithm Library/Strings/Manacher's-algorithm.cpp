// Manacher's Algorithm
// for finding queries related to palindromes
// Time Complexity  - slighlty more than O(N)
// Space Complexity - O(N)

int n;
vector<int> d1(n); // d1[i] denotes length of odd length palin at center i.
vector<int> d2(n); // d2[i] denotes length of even length palin at center i.

void manacher(){
    // for even length palindromes
    for(int i=0, l=0, r=-1; i<n; ++i){
        int len = (i>r)? 0: min( d2[l+r-i+1], r-i+1);
        while (0<=i-len-1 && i+len<n && s[i-len-1]==s[i+len]){
            len++;
        }
        d2[i] = len--;
        if (i+len > r) {
            l = i-len-1;
            r = i+len;
        }
    }
    // for odd length palindromes
    for (int i=0, l=0, r=-1; i<n; ++i){
        int len = (i>r)? 1: min( d1[l+r-i], r-i+1);
        while (0<=i-len && i+len<n && s[i-len]==s[i+len]){
            len++;
        }
        d1[i] = len--;
        if (i+len > r){
            l = i-len;
            r = i+len;
        }
    }
    ////

    ////
}