// Author : Adarsh Gaur 
#include <bits/stdc++.h>
using namespace std;
#define int int64_t

// RMQ with Sparse Table
// Time Complexity 				- O(NlogN) for precomputation
// For Idempotent Functions 	- O(1) for query
// For non-idempotent function 	- O(logN) for query
// Space Complexity				- O(NlogN)

int const MAXN = 2e5 +7;
int const K = int(log2(MAXN)) +1;

int n;
int Log[MAXN+1];
int A[MAXN];
int ST[K][MAXN];
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
		ST[0][i] = i;
	}

	// compute the other layers Sparse Table
	for(int j=1; j<K; j++){
		for(int i=0; i + (1<<j)-1 <n; i++){
			if( A[ ST[j-1][i] ] <  A[ ST[j-1][i + (1<<(j-1))] ]){
				ST[j][i] = ST[j-1][i];
			}else{
				ST[j][i] = ST[j-1][i+(1<<(j-1))];
			}
		}
	}
}

int query(int left ,int right){
	if(right < left)
		swap(left,right);
	int j = Log[right-left+1];
	return min(A[ ST[j][left] ], A[ ST[j][right-(1<<j) +1] ]);
}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	ComputeLogs();
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
	pre();
	int q;cin>>q;
	while(q--){
		int l ,r;
		cin>>l>>r;
		cout<<query(l,r)<<endl;
	}
	return 0;
}
