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
	string s;
	cin>>s;
	int n =s.size();
	if((s[n-1]-'0')%2==0){
		cout<<0<<endl;
	}else if((s[0]-'0')%2==0){
		cout<<1<<endl;
	}else{
		int c=0;
		c += count(s.begin(), s.end(), '2');
		c += count(s.begin(), s.end(), '8');
		c += count(s.begin(), s.end(), '6');
		c += count(s.begin(), s.end(), '4');
		if(c>0){
			cout<<2<<endl;
		}else{
			cout<<-1<<endl;
		}
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
