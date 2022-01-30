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
//int const mod = 998244353;
//int const N = 1e5 + 7;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int n, k;cin>>n>>k;
	string a;cin>>a;
	cout<<n<<endl;
	string s = a.substr(0,k);
	for(int i=k; i<n; i++){
		s += s[i-k];
	}
	if( s >= a){
		cout<<s<<endl;
	}else{
		for(int i=k-1; i>=0; i--){
			if(s[i] != '9'){
				s[i]++;
				break;
			}
			s[i]='0';
		}
		for(int i=k; i<n; i++){
			s[i] = s[i-k];
		}
		cout<<s<<endl;
	}
	return 0;
}
