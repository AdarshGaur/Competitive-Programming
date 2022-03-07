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
//const int mod = 1e9 +7;
const int mod = 998244353;


void solve(){
	int k;
	string s;
	cin>>k;
	if(k%25==0){
		cout<<0<<endl;
		return;
	}
	s = to_string(k);
	int n = (int)s.size();
	//25
	int x=0, temp=0, ans=INF;	
	for(int i=n-1; i>=0; i--){
		if(x==0 && s[i]=='5'){
			x++;
		}else if(x==1 && s[i]=='2'){
			break;
		}else{
			temp++;
		}
	}
	ans = min(ans,temp);
	//75
	temp=0;
	x=0;
	for(int i=n-1; i>=0; i--){
		if(x==0 && s[i]=='5'){
			x++;
		}else if(x==1 && s[i]=='7'){
			break;
		}else{
			temp++;
		}
	}
	ans = min(ans,temp);
	//50
	temp=0;
	x=0;
	for(int i=n-1; i>=0; i--){
		if(x==0 && s[i]=='0'){
			x++;
		}else if(x==1 && s[i]=='5'){
			break;
		}else{
			temp++;
		}
	}
	ans = min(ans,temp);
	//00
	temp=0;
	x=0;
	for(int i=n-1; i>=0; i--){
		if(x==0 && s[i]=='0'){
			x++;
		}else if(x==1 && s[i]=='0'){
			break;
		}else{
			temp++;
		}
	}
	ans = min(ans,temp);
	cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
    
    int times=1;
    cin >> times;
    for(int i=1;i<=times; ++i){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
