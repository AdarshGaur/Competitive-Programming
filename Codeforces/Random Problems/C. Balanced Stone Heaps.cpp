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
int const N = 2e5 + 7;

int n;
int h[N];

bool check(int x){
	int aux[n]={0};
	for(int i=n-1; i>1; i--){
		if(aux[i] + h[i] < x)return false;
		else if(aux[i] + h[i] == x)continue;
		int g = aux[i]+h[i]-x;
		g = min(g, h[i]);
		int p = g/3;
		aux[i-1] += p;
		aux[i-2] += 2*p;
	}
	if(h[0]+aux[0]<x or h[1]+aux[1]<x)return false;
	return true;
}

void solve(){
	cin>>n;
	int lo=INF;
	for(int i=0; i<n; i++){
		cin>>h[i];
		lo = min(lo, h[i]);
	}
	int ans=1, hi=h[n-1];
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if( check(mid) ){
			lo = mid+1;
			ans = mid;
		}else{
			hi = mid-1;
		}
	}
	cout<<ans<<endl;
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
