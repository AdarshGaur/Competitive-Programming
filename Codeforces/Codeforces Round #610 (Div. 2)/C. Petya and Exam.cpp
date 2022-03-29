// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;

void solve(){
	int n, t, a, b, totale=0, totalh=0;
	cin >> n >> t >> a >> b;
	vector<pii> ques(n, {0,0});
	for(int i=0; i<n; i++){
		cin >> ques[i].ss; // easy or hard
		(ques[i].ss == 0 ? totale++ : totalh++);
	}
	for(int i=0; i<n; i++){
		cin >> ques[i].ff; // time limit for the question
	}
	sort(ques.begin(), ques.end());
	ques.push_back({t+1, 0});
	int i=0, j=0, easy=0, hard=0, ans=0;
	while( i <= n){
		int needed = easy * a  + hard * b;
		int has = ques[i].ff -1 - needed;
		if( has >= 0){
			int extras = min(has/a, totale - easy);
			has -= extras * a;
			extras += min(has/b, totalh - hard);
			// has -= some * b;
			ans = max(ans, easy + hard + extras);
		}
		j = i;
		while(j <=n and ques[i].ff == ques[j].ff){
			if(ques[j++].ss) hard++;
			else easy++;
		}
		i = j;
	}
	cout << ans << endl;
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
