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

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 1e5 + 7;


void solve(){
	int n;cin>>n;
	int carry=0;
	deque<string> ss;
	for(int i=0; i<n; i++){
		string s;cin>>s;
		if(s.size()%2==0){
			ss.push_front(s);
		}else{
			ss.push_back(s);
		}
	}
	while(!ss.empty()){
		string s = ss.front();
		ss.pop_front();
		int o = count(s.begin(), s.end(), '0');
		int z = s.size() - o;
		if(carry){
			if(z>o){
				z--;
				o++;
			}else{
				o--;
				z++;
			}
		}
		carry=0;
		if(o%2==1 and z%2==1 and s.size()%2==0){
			carry=1;
		}
	}
	if(carry)n--;
	cout<<n<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.precision(20);
    int test=1;
    cin >> test;
    for(int i=1;i<=test; i++){
        //cout<<"Case #"<< i << ": ";
        solve();
    }
    return 0;
}
