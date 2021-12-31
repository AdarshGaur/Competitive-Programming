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
	int n,s;cin>>n>>s;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int j=0, sum=s, ans=0, x=0, y=0;
	for(int i=0; i<n; i++){
		sum += a[i];
		while(j<n && sum<0){
			sum -= a[j++];
		}
		if(sum>=0 and ans<i-j+1){
			ans = i-j+1;
			x = j+1;
			y = i+1;
		}
	}
	if(ans==0){
		cout<<-1<<endl;
	}else{
		cout<<x<<" "<<y<<endl;
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
