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
int const N = 1e6 + 7;
bool a[N];

void solve(){
	int n;cin>>n;
	for(int i=0; i<n; i++){
		int pos;cin>>pos;
		a[pos] = true;
	}
	int cnt=0;
	for(int i=1; i<N; i++){
		int g = 0;
		for(int j=i; j<N; j+=i){
			if(a[j]){
				g  = __gcd(g, j);
			}
		}
		cnt += (g==i?1:0);
	}
	cout<<cnt-n<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    //cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
