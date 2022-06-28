// Author : @AdarshGaur

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
typedef pair<int,int> pii;


// Source : https://codeforces.com/blog/entry/76087
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
#define debug(...) "Yume o akiramete shinde kure."
#endif


int solve(){
	
	int n;
	cin >> n;
	
	int a[n];
	for(int &i : a)
		cin >> i;
	
	if(n == 1) return 0;
	if(a[0] == 1 and a[n-1] == n) return 1;
	if(a[0] == n and a[n-1] == 1) return 1;
	
	vector<int> minpref(n, 0), maxpref(n, 0), minsuf(n), maxsuf(n);
	maxsuf[n-1] = n-1, minsuf[n-1] = n-1;
	
	for(int i=1; i<n; i++){
		///// for min and max prefix
		if(a[i] < a[minpref[i-1]]){
			minpref[i] = i;
		}else{
			minpref[i] = minpref[i-1];
		}
		if(a[i] > a[maxpref[i-1]]){
			maxpref[i] = i;
		}else{
			maxpref[i] = maxpref[i-1];
		}
		
		//// min - max suffix;
		if(a[n-1-i] < a[minsuf[n-i]]){
			minsuf[n-1-i] = n-1-i;
		}else{
			minsuf[n-1-i] = minsuf[n-i];
		}
		if(a[n-1-i] > a[maxsuf[n-i]]){
			maxsuf[n-1-i] = n-1-i;
		}else{
			maxsuf[n-1-i] = maxsuf[n-i];
		} 
	}
	
	auto jumps = [&](auto self, int l, int r){
		if(l == r) return 0;
		if(l == 0){
			int ri = minpref[r], rj = maxpref[r];
			if((ri == l and rj == r) or (ri == r and rj == l))
				return 1;
			return self(self, l , min(ri, rj)) + self(self, max(ri, rj), r)+1;
		}
		int li = minsuf[l], lj = maxsuf[l];
		if((li == l and lj == r) or ( li == r and lj == l))
			return 1;
		return self(self, l, min(li, lj)) + self(self, max(li, lj), r)+1;
	};
	
	return jumps(jumps, 0, n-1);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	int test=1;
	cin >> test;
	for(int t=1; t<=test; t++){
		// cout<<"Case #"<<t<<": ";
		cout << solve() << endl;
	}
	return 0;
}
