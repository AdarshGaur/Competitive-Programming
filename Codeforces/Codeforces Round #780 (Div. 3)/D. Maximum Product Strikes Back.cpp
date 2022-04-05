// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > (int)0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef cicada
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) "Throughout the hells, I alone am the honored one."
#endif

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	int n;
	cin >> n;
	int a[n];
	for(auto &i : a) cin >> i;
	int mx=0, l=0, r=-1;
	for(int i=0; i<n; i++){
		if(a[i] == 0) continue;
		int j=i, cnt=0, p=1;
		while(j<n and a[j] != 0){
			cnt += (abs(a[j]) == 2);
			p *= (a[j] < 0 ? -1 : 1);
			j++;
		}
		j--;
		int k = j, left=i, right=j;
		while(i <= j and p < 0 and mx < cnt){
			if(a[i] == -1){
				left = i+1, p *= -1;
			}else if(a[j] == -1){
				right = j-1, p *= -1;
			}else if(a[i] == 1){
				i++;
			}else if(a[j] == 1){
				j--;
			}else if(a[i] == -2){
				left = i+1;
				p *= -1, cnt--;
			}else if(a[j] == -2){
				right = j-1, p*=-1, cnt--;
			}else{
				i++, j--, cnt--;
			}
		}
		if( mx < cnt){
			mx = cnt;
			l = left, r = right;
		}
		i = k;
	}
	cout << l << " " << n-1-r << "\n"; 
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
