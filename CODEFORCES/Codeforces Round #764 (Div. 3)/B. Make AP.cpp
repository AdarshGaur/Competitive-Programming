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
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n =3;
	int a[4][3];
	for(int i=0; i<n; i++){
		cin>>a[0][i];
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<n; j++){
			a[i][j] = a[0][j];
		}
	}
	int ab = a[0][0], b=a[0][1], c = a[0][2];
	int ma, mb, mc;
	mb = (ab+c)/2;
	ma = b + (b-c);
	mc = b + (b-ab);
	a[1][2] = mc;
	a[2][1] = mb;
	a[3][0] = ma;
	for(int i=0; i<=n; i++){
		if(a[i][1] - a[i][0] == a[i][2] - a[i][1] ){
			if(a[i][0]%ab==0 and a[i][1]%b==0 and a[i][2]%c==0 and a[i][0]/ab >0 and a[i][1]/b >0 and a[i][2]/c >0){
				yes;
				return;
			}
		}
	}
	no;
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
