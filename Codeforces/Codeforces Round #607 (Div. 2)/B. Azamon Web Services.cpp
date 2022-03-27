// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;

string solve(){
	string s, c;
	cin >> s >> c;
	int n = s.size(), m = c.size();
	string temp = s;
	sort(temp.begin(), temp.end());
	for(int i=0; i<n; i++){
		if(temp[i] != s[i]){
			int j = n-1;
			while(s[j] != temp[i]){
				j--;
			}
			swap(s[i], s[j]);
			break;
		}
	}
	string ans = s;
	int i=0, j=0;
	while(i < n and j < m){
		if(s[i] < c[j] ) return s;
		if(s[i] > c[j] ) return "---";
		i++, j++;
	}
	if(i == n and j != m) return s;
	return "---";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		cout << solve() << endl;
	}
	return 0;
}
