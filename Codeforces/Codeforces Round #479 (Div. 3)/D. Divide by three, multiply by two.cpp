// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define aster(x) cerr<<#x<<" = "<<x<<endl;
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define ff first
#define ss second

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;

void solve(){
	int n;cin>>n;
	vi a(n);
	for(int i=0; i<n; i++)cin>>a[i];
	sort(a.begin(), a.end());
	int j=n;
	vi res;
	for(int i=1; i<n; i++){
		if( a[i-1]%3==0 && find(a.begin(), a.end(), a[i-1]/3) != a.end() ){
			auto ik = find(a.begin(), a.end(), a[i-1]/3) - a.begin();
			swap(a[ik], a[i]);
		}else if(find(a.begin(), a.end(), a[i-1]*2) != a.end() ){
			auto ik = find(a.begin(), a.end(), a[i-1]*2) - a.begin();
			swap(a[ik], a[i]);
		}else{
			j=i;
			break;
		}
	}
	int ff = a[0];
	for(int i=j; i<n; i++){
		if( find(a.begin(), a.end(), ff*3) != a.end() ){
			ff *= 3;
			res.push_back(ff);
		}else if(ff%2==0 && find(a.begin(), a.end(), ff/2) != a.end() ){
			ff/=2;
			res.push_back(ff);
		}
	}
	if(j==n-1 && res.size()==0){
		j++;
	}
	///output
	for(int i=res.size()-1; i>=0; i--){
		cout<<res[i]<<" ";
	}
	for(int i=0; i<j; i++){
		cout<<a[i]<<" ";
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
    int testcases=1;
    //cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}
