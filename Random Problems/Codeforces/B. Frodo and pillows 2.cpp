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
int n,m,k,ans=1;

int summ(int x){
	return (x*(x+1))/2;
}

int eval(int len, int x){
	int res=0;
	if(x<=len){
		res = summ(x) + (len-x);
	}else{
		res = summ(x) - summ(x-len);
	}
	return res;
}

bool poss(int x){
	int res = x + eval(k-1, x-1) + eval(n-k, x-1);
	if(res<=m){
		ans=x;
		return true;
	}else{
		return false;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////
    cin>>n>>m>>k;
    int lo=0, hi=m;
    while(lo<hi){
		int mid=(lo+hi)/2;
		if(poss(mid+1)){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}
	cout<<lo<<endl;
    return 0;
}
