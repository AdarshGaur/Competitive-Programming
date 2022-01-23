// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ii(x) (int)(x)

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	string s;cin>>s;
	int n = s.size();
	for(int i=n-1; i>0; i--){
		int x = s[i]-'0' + s[i-1]-'0';
		if(x >= 10){
			s[i] = '0' + x%10;
			s[i-1] = '0' + x/10;
			cout<<s<<endl;
			return;
		}
	}
	int x = s[0]-'0' + s[1]-'0';
	s[1] = '0' + x;
	for(int i=1; i<n; i++){
		cout<<s[i];
	}
	cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
