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
	int n;cin>>n;
	int p[n];
	for(int i=0; i<n; i++)cin>>p[i];
	vector<bool> vis(n+1, false);
	vis[0]=true;
	int pos=0;
	for(int i=0; i<n; i++){
		if(p[i]==1){
			pos=i;break;
		}
	}
	vis[1]=true;
	string side(n+1,'L');
	for(int i=pos; i<n; i++){
		side[p[i]]='R';
	}
	string ans="1";
	int i=pos-1, j=pos+1, cnt=2, mx=1;
	while(i>=0 and j<n and cnt<=n){
		if(!vis[cnt]){
			if(side[cnt]=='R'){
				while(p[j]!=cnt){
					vis[p[j]]=true;
					mx = max(mx, p[j++]);
				}
				vis[p[j]]=true;
			}else{
				while(p[i]!=cnt){
					vis[p[i]]=true;
					mx = max(mx, p[i--]);
				}
				vis[p[i]]=true;
			}
			mx = max(mx, cnt);
		}
		if(mx==cnt){
			ans += "1";
		}else{
			ans += "0";
		}
		cnt++;
	}
	while(i>=0 and cnt<=n){
		if(!vis[cnt]){
			while(p[i]!=cnt){
				vis[p[i]]=true;
				mx=max(mx, p[i]);
				i--;
			}
			vis[p[i]]=true;
			mx = max(mx, cnt);
		}
		if(mx == cnt)ans += "1";
		else ans += "0";
		cnt++;
	}
	while(j<n and cnt<=n){
		if(!vis[cnt]){
			while(p[j]!=cnt){
				vis[p[j]]=true;
				mx=max(mx, p[j]);
				j++;
			}
			vis[p[j]]=true;
			mx = max(mx, p[j]);
		}
		if(mx == cnt)ans += "1";
		else ans += "0";
		cnt++;
	}
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
