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

char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};


void solve(){
	string kingdom;cin>>kingdom;
	for(auto i: vowels){
		if(kingdom.back() == i){
			cout<<kingdom<<" is ruled by Alice."<<endl;
			return;
		}
	}
	if(kingdom.back() == 'y' or kingdom.back()=='Y'){
		cout<<kingdom<<" is ruled by nobody."<<endl;
		return;
	}
	cout<<kingdom<<" is ruled by Bob."<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
