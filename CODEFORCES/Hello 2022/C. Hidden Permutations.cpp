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
//int const mod = 998244353;
int const N = 1e4 + 7;

int n, q;
vi p;
int query(int x){
	if(q>2*n)exit(0);
	cout<<"? "<<x<<endl;
	cout.flush();
	int y;cin>>y;
	q++;
	return y;
}

void print(){
	cout<<"! ";
	for(int i=1; i<=n; i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
	cout.flush();
}


void solve(){
	cin>>n;
	q=0;
	p = vi(n+1, 0);
	for(int i=1; i<=n; i++){
		if(!p[i]){
			deque<int> dq;
			int start = query(i), nx = query(i);
			dq.push_back(start);
			dq.push_back(nx);
			while(dq.back() != dq.front()){
				nx = query(i);
				dq.push_back(nx);
			}
			while(dq.size() > ii(1)){
				int x = dq.front();
				dq.pop_front();
				p[x] = dq.front();
			}
		}
	}
	print();
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
