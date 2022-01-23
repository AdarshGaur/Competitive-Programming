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
	for(auto &i : a)cin>>i;
	int freq[n+1]={0};
	for(int i=0; i<n; i++){
		freq[a[i]]++;
	}
	vi ans;
	int i=0;
	while(i<n){
		int mex=0;
		while(freq[mex]>0)mex++;
		vector<bool> vis(mex+1, false); // making a local boolean array is dead on best here !
		int tmex=0;
		while(i<n){
			freq[a[i]]--;
			if(a[i]<mex and !vis[a[i]]){ //a[i] can be more than mex also
				vis[a[i]]=true;
				tmex++;
			}
			i++;
			if(tmex==mex)break;
		}
		ans.push_back(mex);
	}
	cout<<ans.size()<<endl;
	for(auto j: ans){
		cout<<j<<" ";
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
