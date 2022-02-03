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


int solve(){
	string s;cin>>s;
	int n = stoi(s);
	if(n%7==0){
		return n;
	}
	for(int i=s.size()-1; i>=0; i--){
		string k = s;
		for(int j=0; j<=9; j++){
			k[i] = to_string(j)[0];
			int x = stoi(k);
			if(x%7==0){
				return x;
			}
		}
	}
	return n;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	while(test--)
		cout<<solve()<<endl;
	return 0;
}
