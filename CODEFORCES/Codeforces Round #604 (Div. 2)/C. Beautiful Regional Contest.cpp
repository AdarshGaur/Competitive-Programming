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


void solve(){
	int n;cin>>n;
	int half = n/2;
	half++;
	vi p(half);
	for(int i=0; i<half;i++){
		cin>>p[i];
	}
	for(int i=half; i<n; i++){
		int temp;cin>>temp;
	}
	n = half;
	int last = p[n-1];
	while(n>1 and p.back() == last){
		p.pop_back();
		n--;
	}
	int g=0, s=0, b=0, i=0;
	last = p[0];
	while(i<n and p[i]==last){
		g++;
		i++;
	}
	if(i<n)last=p[i];
	while(i<n and g>=s){
		s++;
		last = p[i];
		i++;
	}
	while(i<n and p[i]==last){
		s++;
		i++;
	}
	if(i<n)last = p[i];
	while(i<n and g>=b){
		b++;
		last=p[i];
		i++;
	}
	while(i<n){
		b++;
		i++;
	}
	if(g==0 or s==0 or b==0 or g>=b or g>=s){
		g=0;
		s=0;
		b=0;
	}
	cout<<g<<" "<<s<<" "<<b<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    ////////////////////////

    int testcases=1;
    cin >> testcases;
    for(int i=1;i<=testcases; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }

    return 0;
}
