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
	string s;cin>>s;
	string res;
	int n = s.size();
	for(int i=0; i<n;){
		char c = s[i];
		int cnt=0;
		i++;
		while(i<n and c==s[i]){
			cnt++;
			i++;
		}
		if(cnt%2==0)res += c;
	}
	sort(res.begin(), res.end());
	auto it = unique(res.begin(), res.end());
	for(auto k=res.begin(); k!=it; k++){
		cout<<*k;
	}
	cout<<endl;
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
