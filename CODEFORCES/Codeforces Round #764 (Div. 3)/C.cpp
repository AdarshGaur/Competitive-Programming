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


bool solve(){
	int n;cin>>n;
	multiset<int, greater<int>> a;
	for(int i=0; i<n; i++){
		int p;cin>>p;
		a.insert(p);
	}
	for(int i=n; i>0;){
		int x = *a.begin();
		a.erase(a.begin());
		if(x < i)return false;
		while(x>i)x>>=1;
		if(x==i)i--;
		else a.insert(x);
	}
	return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        cout<< (solve()? "YES" : "NO") <<endl;
    }
    return 0;
}
