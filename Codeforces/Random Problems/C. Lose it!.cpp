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
#define ff first
#define ss second

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int arr[] = {4, 8, 15, 16, 23, 42};
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
		for(int j=0; j<6; j++)
			if(arr[j]==a[i])a[i] = j;
	}
	int ans =0;
	int freq[6] = {0};
	for(int i=0; i<n; i++){
		freq[a[i]]++;
		if(a[i] != 0 and freq[a[i]]>freq[a[i]-1]){
			freq[a[i]]--;
			ans++;
		}
	}
	for(int i=5; i>0; i--){
		ans += (freq[i-1]-freq[i]);
		freq[i-1] = freq[i];
	}
	cout<<ans<<endl;
	return 0;
}
