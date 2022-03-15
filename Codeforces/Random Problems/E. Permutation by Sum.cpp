// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n, l ,r, s;
	cin >> n >> l >> r >> s;
	vi v;
	int left = r - l +1;
	set<int> st;
	for(int i=n; i>0; i--){
		if( ((left*(left-1))/2) <= s-i && left >0){
			v.push_back(i);
			s -= i;
			left--;
		}else{
			st.insert(i);
		}
	}
	if(s!=0){
		cout << -1 << endl;
		return;
	}
	for(int i=0; i<l-1; i++){
		cout << *st.begin() << " ";
		st.erase(st.begin());
	}
	for(int i:v){
		cout << i << " ";
	}
	while(!st.empty()){
		cout << *st.begin() << " ";
		st.erase(st.begin());
	}
	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
