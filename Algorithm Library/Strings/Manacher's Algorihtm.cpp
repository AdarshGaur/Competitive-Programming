/*
 * Author : @AdarshGaur
 * 
 * Manacher's Algorithm : https://cp-algorithms.com/string/manacher.html
 * Time Complexity - O(N)
 * Space Comlexity - O(N)
 * 
 */

#include <bits/stdc++.h>
using namespace std;


// d1[i] - how many palindromes of odd length with center at i
// max odd length of palindrome centered at i -> (d[i]*2)-1;
vector<int> oddPalindromes(const string& s){
	int n = (int)s.size();
	vector<int> d1(n);
	
	int l = 0, r = -1;
	for(int i=0; i<n; i++){
		int k = (i > r ? 1 : min(d1[l + (r-i)], r-i));
		while( i+k < n and i-k >= 0 and s[i+k] == s[i-k])
			k++;
		d1[i] = k--;
		if(i+k > r){
			l = i-k, r = i+k;
		}
	}
	return d1;
}



// d2[i] - how many palindromes of even length with center at i
// max even length of palindrome centered at i -> d[i] * 2;
vector<int> evenPalindromes(const string& s){
	int n = (int)s.size();
	vector<int> d2(n);
	
	int l = 0, r = -1;
	for(int i=0; i<n; i++){
		int k = ( i > r ? 0 : min(d2[l + (r-i+1)], r-i+1)) +1;
		while( i+k-1 < n and i-k >= 0 and s[i+k-1] == s[i-k])
			k++;
		d2[i] = --k;
		if(i + k -1 > r){
			l = i - k, r = i + k -1;
		}
	}
	return d2;
}



signed main()
{
	string s;
	cin >> s;
	
	auto odd_palins = oddPalindromes(s);
	for(size_t i=0; i<s.size(); i++){
		cout << odd_palins[i] << " ";
	}
	cout << endl;
	
	
	auto even_palins = evenPalindromes(s);
	for(size_t i=0; i<s.size(); i++){
		cout << even_palins[i] << " ";
	}
	cout << endl;
	
	
    return 0;
}
