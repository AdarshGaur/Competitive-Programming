// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ff first
#define ss second

const int INF = 2e18;
const int N = 1e5 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	int n, k;cin>>n>>k;
	string s;cin>>s;
	int f[26]={0};
	for(int i=0; i<k; i++){
		char ch; cin>>ch;
		f[ch-'a']=1;
	}
	int cnt=0, ans=0;
	for(int i=0; i<n; i++){
		if(f[s[i]-'a']){
			cnt++;
		}else{
			ans += (cnt*(cnt+1))/2;
			cnt=0;
		}
	}
	ans += (cnt*(cnt+1))/2;
	cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve();
    return 0;
}
