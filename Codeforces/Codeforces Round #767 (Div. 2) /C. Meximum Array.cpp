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
int const N = 2e5 + 7;


void solve(){
	int n;cin>>n;
	int a[n];
	for(auto &i : a)
		cin>>i;
	int pref[n];
	bool vis[N]={false};
	int mex=0, mx=-1, mi=-1;
	for(int i=0; i<n; i++){
		if(a[i]==mex){
			int j = mex;
			vis[j]=true;
			while(vis[j]){
				vis[j]=false;
				j++;
			}
			mex = j;
		}
		if(a[i]>mex)vis[a[i]]=true;
		pref[i] = mex;
		if(pref[i] > mx){
			mx = pref[i];
			mi = i;
		}
	}
	memset(vis, false, sizeof(vis));
	int suf[n];
	mex=0;
	for(int i=n-1; i>=0; i--){
		if(a[i]==mex){
			int j = mex;
			vis[j]=true;
			while(vis[j]){
				vis[j]=false;
				j++;
			}
			mex = j;
		}
		if(a[i]>mex)vis[a[i]]=true;
		suf[i] = mex;
	}
	vi ans(1, mx);
	memset(vis, false, sizeof(vis));
	for(int i=mi+1; i<n; i++){
		mex=0, mx=suf[i];
		while(i<n){
			if(a[i]==mex){
				vis[mex]=true;
				while(vis[mex]){
					vis[mex]=false;
					mex++;
				}
			}
			if(mex==mx)break;
			if(a[i]>mex)vis[a[i]]=true;
			i++;
		}
		ans.push_back(mex);
	}
	cout<<ans.size()<<endl;
	for(auto i: ans){
		cout<<i<<" ";
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
