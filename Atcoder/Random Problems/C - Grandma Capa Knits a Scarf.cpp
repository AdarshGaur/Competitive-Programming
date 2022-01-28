// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define ff first
#define ss second

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;


void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int ans=INF;
	for(auto c='a'; c<='z'; c++){
		int i=0, j=n-1, cnt=0;
		while(i<j){
			if(s[i]!=s[j]){
				if(s[i]!=c and s[j]!=c){
					cnt=INF;
					break;
				}else if(s[i]==c){
					i++;
					cnt++;
				}else{
					j--;
					cnt++;
				}
			}else{
				i++;
				j--;
			}
		}
		ans=min(ans,cnt);
	}
	if(ans==INF)ans=-1;
	cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}
