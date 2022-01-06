// Author : Adarsh Gaur

// Problem Name : Pyramid Traversal
// Problem url : https://www.codechef.com/DEC21B/problems/PYRAMIDMOVES

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define ff first
#define ss second

#define INF 2e18
const int mod = 1e9 +7;
int const N = 1e5 +7;
int arr[N];
int f[N], invf[N];

void fact(){
	f[0]=1;
	invf[0]=invf[1]=1;
	for(int i=1; i<N; i++)
		f[i] = (f[i-1]*i)%mod;
	for(int i=2; i<N; ++i){
		invf[i] = (mod - mod/i) * invf[mod % i] % mod;
    }
    for(int i=1;i<N; ++i){
         invf[i] = (invf[i-1] * invf[i])%mod;
    }
}

void init(){
	arr[0]=0;
	for(int i=1; i<N; i++){
		arr[i] = arr[i-1] + i;
	}
}

pii findpoints(int s){
	int r=N, c;
	int lo=0, hi=N-1;
	while(lo<hi){
		int mid = (hi+lo)/2;
		if( s > arr[mid]){
			lo = mid+1;
		}else{
			r = mid;
			hi = mid;
		}
	}
	c = s-arr[r-1]-1;
	return {r,c};
}

int nCr(int n, int r){
	if(n<1 or r<0 or n<r)return 0;
	if(r==0)return 1;
	int res = (f[n] * invf[r])%mod;
	return (res*invf[n-r])%mod;
}

void solve(){
	int s, e;cin>>s>>e;
	pii x1 = findpoints(s), x2=findpoints(e);
	//cout<<"s : ("<<x1.ff<<","<<x1.ss<<")"<<endl;
	//cout<<"e : ("<<x2.ff<<","<<x2.ss<<")"<<endl;
	cout << nCr(x2.ff-x1.ff, x2.ss-x1.ss)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
	init();
	fact();
    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
