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
#define ss second
#define ff first

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n, m, d;
	cin>>n>>m>>d;
	int c[m];
	for(int i=0; i<m; i++)cin>>c[i];
	vector<pii> planks;
	int start=0;
	for(int i=0; i<m; i++){
		start+=d;
		planks.push_back({start,start+c[i]-1});
		start+=c[i]-1;
	}
	int place[n+1]={0};
	int i=m-1;
	for(int j=n; j>=0 and i>=0;){
		if(planks[i].ss >= j){
			while(c[i]>0 and j>=0){
				place[j--]=i+1;
				c[i]--;
			}
			i--;
			if(c[i]>0 and j<0){
				cout<<"NO"<<endl;
				return;
			}
		}else{
			j--;
		}
	}
	int mx=0, cnt=0;
	for(int k=1; k<=n; k++){		
		if(place[k]==0){
			cnt++;
			mx = max(cnt, mx);
		}else{
			cnt=0;
		}
	}
	if(mx>=d){
		cout<<"NO"<<endl;
		return;
	}
	////
	cout<<"YES"<<endl;
	for(int k=1; k<=n; k++){
		cout<<place[k]<<" ";
	}
	cout<<endl;
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
