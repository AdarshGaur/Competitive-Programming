/* 
 * Author : Adarsh Gaur 
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fore(i,s,e) for(int i=s; i<e; ++i)
#define trace(it, cont) for(auto it=cont.begin(); it!=cont.end(); ++it)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define abs(x) ((x < 0)?-(x):(x))
#define PI 3.141592653589793238462
#define pb push_back
#define ff first
#define ss second


#ifndef ONLINE_JUDGE
#define aster(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define aster(x)
#endif


void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(unsigned int t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



/////// Main Logical code starts from here ////////

#define INF 2e18
const int mod = 1e9 +7;
//const int mod = 998244353;

vector<vi> adj;

void dfs(int cur, int par=-1){
	sort(all(adj[cur]));
	cout<<cur<<" ";
	for(auto i: adj[cur]){
		if(i==par){
			continue;
		}
		dfs(i, cur);
		cout<<cur<<" ";
	}
}

void solve(){
	int n; cin>>n;
	adj.resize(n+1);
	fore(i,0,n-1){
		int x, y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1);
	cout<<endl;
}

signed main()
{
    fast_io;
    cout.precision(20);
    //int times;cin >> times;
    //for(int i=1;i<=times; ++i){
        //cout<<"Case #"<< i << ": ";
        solve();
    //}
    return 0;
}
