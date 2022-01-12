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
	int n;cin>>n;
	int p[n];
	for(int i=0; i<n; i++)
		cin>>p[i];
	multiset<int, greater<int> > a;
	for(int i=0; i<n; i++){
		while(p[i] > n)
			p[i]>>=1;
		a.insert(p[i]);
	}
	vector<bool> vis(n+1, false);
	while(!a.empty()){
		int x = *a.begin();
		if(vis[x]){
			x>>=1;
			if(x>0)
				a.insert(x);
		}else{
			vis[x]=true;
		}
		a.erase(a.begin());
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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
