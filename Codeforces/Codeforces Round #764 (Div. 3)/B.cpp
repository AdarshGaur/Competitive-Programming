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
	int a, b, c;
	cin>>a>>b>>c;
	if((2*b -c)>0 and (2*b-c)%a==0){
		cout<<"YES"<<endl;
	}else if((2*b -a)>0 and (2*b-a)%c==0){
		cout<<"YES"<<endl;
	}else if((a+c)%(2*b)==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
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
