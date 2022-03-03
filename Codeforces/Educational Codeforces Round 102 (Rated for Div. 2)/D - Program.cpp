// Author : Adarsh Gaur 

// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;

int const INF = 2e12;
int const mod = 1e9 +7;

int const MAXN = 2e5 +7;
int const K = int(log2(MAXN)) +1;

int n;
int Log[MAXN+1];
int A[MAXN];
int ST[K][MAXN];
int ST1[K][MAXN];
// ST[i][j] - index of minimum value from jth index till length 2^i


void ComputeLogs(){
	// store the log values
	Log[1]=0;
	for(int i=2; i<=MAXN; i++){
		Log[i] = Log[i/2]+1;
	}
}


void pre(){
	// Initialize the Sparse Table
	for(int i=0; i<n; i++){
		ST[0][i] = ST1[0][i] = i;
	}

	// compute the other layers Sparse Table
	for(int j=1; j<K; j++){
		for(int i=0; i + (1<<j)-1 <n; i++){
			if(A[ ST1[j-1][i] ] > A[ ST1[j-1][i + (1<<(j-1))] ]){
				ST1[j][i] = ST1[j-1][i];
			}else{
				ST1[j][i] = ST1[j-1][i+(1<<(j-1))];
			}
			if( A[ ST[j-1][i] ] <  A[ ST[j-1][i + (1<<(j-1))] ]){
				ST[j][i] = ST[j-1][i];
			}else{
				ST[j][i] = ST[j-1][i+(1<<(j-1))];
			}
		}
	}
}

pii query(int left ,int right){
	if(right < left)
		return {-INF, INF};
		// swap(right, left);
	int j = Log[right-left+1];
	int mn = min(A[ ST[j][left] ], A[ ST[j][right-(1<<j) +1] ]);
	int mx = max(A[ ST1[j][left] ], A[ ST1[j][right-(1<<j)+1] ]);
	return {mx, mn};
}

void solve(){
	int m;
	cin>>n>>m;
	string s;cin>>s;
	int x=0;
	for(int i=0; i<n; i++){
		x += (s[i]=='+'? 1:-1);
		A[i] = x;
	}
	pre();
	while(m--){
		int l, r;cin>>l>>r;
		l--, r--;
		auto [mx, mn] = query(r+1, n-1);
		auto [a, b] = query(0, l-1);
		int extra=1;
		if(l == 0 and r == n-1){
			cout << 1 << endl;
		}else if(l==0){
			int next = A[r+1] + (s[r+1]=='+' ? -1 : 1);
			mx -= next;
			mn -= next;
			if(mx<0 or mn>0)extra++;
			cout << mx - mn + extra << endl;
		}else if(r==n-1){
			if( a < 0 or b > 0)extra++;
			cout << a - b + extra << endl;
		}else{
			int next = A[r+1] + (s[r+1]=='+' ? -1 : 1);
			int dif = next - A[l-1] ;
			mn -= dif;
			mx -= dif;
			mx = max(a, mx);
			mn = min(b, mn);
			if(mx<0 or mn>0)extra++;
			cout << mx - mn + extra << endl;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	ComputeLogs();
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
