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



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

    int n, d, h;
    cin>>n>>d>>h;
    if(d > 2*h or (h==1 and d==1 and n!=2)){
		cout<<-1<<endl;
		return 0;
	}
	////for h height
	int x=h;
	int a=1, b=2;
	while(x--){
		cout<<a<<" "<<b<<endl;
		a=b++;
	}
	/// for d diameter
	x = d-h;
	a=1;
	while(x--){
		cout<<a<<" "<<b<<endl;
		a=b++;
	}
	a=1;
	if(h==d){
		a++;
	}
	///leftovers
	while(b<=n){
		cout<<a<<" "<<b<<endl;
		b++;
	}
    return 0;
}
