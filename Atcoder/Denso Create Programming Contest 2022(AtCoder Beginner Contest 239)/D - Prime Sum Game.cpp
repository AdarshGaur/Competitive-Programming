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
int const N = 1e3 + 7;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	vector<bool> isprime(N, true);
	isprime[0] = isprime[1] = false;
	for(int i=2; i<N; i++){
		if(isprime[i]){
			for(int j=i+i; j<N; j+=i){
				isprime[j]=false;
			}
		}
	}
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	string win = "Takahashi";
	for(int i=a; i<=b; i++){
		bool pos=false;
		for(int j=c; j<=d; j++){
			if(isprime[i+j]){
				pos=true;
				break;
			}
		}
		if(!pos){
			cout<<win<<endl;
			return 0;
		}
	}
	cout<<"Aoki"<<endl;
	return 0;
}
