// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, p=1;
	cin >> n;
	vector<int> subseq;
	for(int i=1; i<n-1; i++){
		if( __gcd(n,i) == 1){
			p = (p*i)%n;
			subseq.push_back(i);
		}
	}
	if( p == n-1){
		subseq.push_back(n-1);
	}
	cout << subseq.size() << "\n";
	for(int i:subseq){
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}
