// Author : Adarsh Gaur 

// Throughout the hell, I alone am the honored one.

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

string solve(){
	string s;
	cin >> s;
	int sum=0;
	for(auto i: s){
		sum += (i-'0');
	}
	if(sum%9 == 0){
		string t = s.substr(0,1) + '0';
		if(s.size() > 1){
			t += s.substr(1);
		}
		return t;
	}
	int n = 9 - sum%9;
	auto c = ('0' + n);
	for(int i=0; i<(int)s.size(); i++){
		if( s[i] > c ){
			string t = s.substr(0,i);
			t += c;
			t += s.substr(i);
			return t;
		}
	}
	s += c;
	return s;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		cout<<"Case #"<<t<<": " << solve() << endl;
	}
	return 0;
}
