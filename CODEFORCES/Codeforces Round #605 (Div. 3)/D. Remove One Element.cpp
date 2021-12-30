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
    int n;cin>>n;
    int a[n];
    for(int i=0; i<n;i++){
		cin>>a[i];
	}
	int start=0, ans=1;
	for(int i=0; i<n; i++){
		if(i==0 and a[i]>=a[i+1]){
			start=1;
		}else if(i==n-1 and a[i]<=a[i-1]){
			n--;
		}else{
			if(a[i]>a[i-1] and a[i]<a[i+1]){
				continue;
			}else if(a[i+1]>a[i-1]){
				int j=i+1;
				while(j<n-1 and a[j]<a[j+1]){
					j++;
				}
				ans = max(ans, j-start);
				if(a[i]<a[i+1]){
					start=i;
				}else{
					start=i+1;
				}
				i=j-1;
			}else if(a[i]>a[i-1]){
				ans = max(ans, i-start+1);
			}else{
				start = i;
			}
		}
	}
	ans = max(ans,n-start);
	cout<<ans<<endl;
    return 0;
}
