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
vector<int> oddPalindromes(string s){
	int n = (int)s.size();
	s = '$' + s + '^';
	vector<int> d1(n+2);
	int l = 1, r = 1;
	for(int i=1; i<=n; i++){
		d1[i] = max<int>(0, min(d1[l + (r-i)], r-i));
		while( s[i - d1[i]] == s[i + d1[i]])
			d1[i]++;
		if(i + d1[i] > r){
			l = i - d1[i], r = i + d1[i];
		}
	}
	return vector<int>(begin(d1)+1, end(d1)-1);
}



// d2 - how many palindromes of even length with center at i
// max even length of palindrome centered at i -> d2[i] * 2;
vector<int> evenPalindromes(string s){
	string p;
	for(auto &c: s)
		p += string("#") + c;
	
	auto d = oddPalindromes(p + '#');
	vector<int> d2;
	for(int i=0; i<(int)d.size(); i+=2){
		int x = (d[i]-1) /2;
		d2.emplace_back(x);
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
