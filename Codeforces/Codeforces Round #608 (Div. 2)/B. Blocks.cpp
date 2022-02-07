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
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int w = count(s.begin(), s.end(), 'W');
	int b = n-w;
	if(w&1 and b&1){
		cout<<-1<<endl;
	}else{
		vi ans;
		if(w&1){
			for(int i=0; i<n-1; i++){
				if(s[i]=='B'){
					s[i]='W';
					ans.push_back(i+1);
					if(s[i+1]=='W'){
						s[i+1]='B';
					}else{
						s[i+1]='W';
					}
				}
			}
		}else{
			for(int i=0; i<n-1; i++){
				if(s[i]=='W'){
					s[i]='B';
					ans.push_back(i+1);
					if(s[i+1]=='W'){
						s[i+1]='B';
					}else{
						s[i+1]='W';
					}
				}
			}
		}
		cout<<ans.size()<<endl;
		if(ans.size()){
			for(int i:ans){
				cout<<i<<" ";
			}
			cout<<endl;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	// cin >> test;
	while(test--)
		solve();
	return 0;
}
