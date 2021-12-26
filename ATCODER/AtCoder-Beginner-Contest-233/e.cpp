// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define ff first
#define ss second

const int INF = 2e18;
const int N = 1e5 +7; //// check the constraints
const int mod = 1e9 +7;
//const int mod = 998244353;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
	string x;cin>>x;
	int n = (int)x.size();
	int sum[n+1];
	sum[0]=0;
	for(int i=1; i<=n; i++){
		sum[i] = x[i-1]-'0';
		sum[i] += sum[i-1];
	}
	string res;
	for(int i=n; i>0; i--){
		int carry = sum[i]/10;
		sum[i] %= 10;
		res += to_string(sum[i]);
		sum[i-1] += carry;
	}
	string last = to_string(sum[0]);
	reverse(last.begin(), last.end());
	res += last;
	while(res.back() == '0'){
		res.pop_back();
	}
	reverse(res.begin(), res.end());
	cout<<res<<endl;
    return 0;
}
