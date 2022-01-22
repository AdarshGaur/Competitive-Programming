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
	int n;cin>>n;
	vi a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	vi b = a;
	sort(b.begin(), b.end());
	int ans=0, start=0;
	multiset<int> ab, ba;
	for(int i=0; i<n; i++){
		auto it1 = ba.find(a[i]);
		if(it1!=ba.end())
			ba.erase(it1);
		else
			ab.insert(a[i]);
		auto it2 = ab.find(b[i]);
		if(it2 != ab.end())
			ab.erase(it2);
		else
			ba.insert(b[i]);
		if(ab.empty() && ba.empty()){
			ans += b[i] - b[start];
			start = i+1;
		}
	}
	cout<<ans<<endl;
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
