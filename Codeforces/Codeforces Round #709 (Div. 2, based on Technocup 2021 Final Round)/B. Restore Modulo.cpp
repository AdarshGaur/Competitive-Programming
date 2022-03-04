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
	int a[n];
	int mx=-1;
	for(int i=0; i<n; i++){
		cin>>a[i];
		mx = max(mx, a[i]);
	}
	if(n==1){
		cout<<0<<endl;
		return;
	}
	vi ps, ng;
	int c=-1, m=-1;
	for(int i=1; i<n; i++){
		if(a[i]-a[i-1]<0){
			ng.push_back(a[i]-a[i-1]);
			m=a[i-1]-a[i];
		}else{
			ps.push_back(a[i]-a[i-1]);
			c = a[i]-a[i-1];
		}
	}
	int ans=0;
	for(auto i:ps){
		if(i!=ps.back()){
			ans=-1;
			break;
		}
	}
	if(c==0 && (int)ng.size()){
		ans=-1;
	}
	for(auto i:ng){
		if(i!=ng.back()){
			ans=-1;
			break;
		}
	}
	if(m!=-1 && c!=-1 && m+c <= mx){
		ans=-1;
	}
	if(ans==-1){
		cout<<-1<<endl;
	}else if(c==-1 || m==-1){
		cout<<0<<endl;
	}else{
		m+=c;
		cout<<m<<" "<<c<<endl;
	}
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
