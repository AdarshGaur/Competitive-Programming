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

int const INF = 2e18;
int const mod = 1e9 +7;
// int const mod = 998244353;
// int const N = 2e5 + 7;


void solve(){
	string s;
	cin >> s;
	bool type1 = false;
	// step 1 : identify the type of coordinates
	int r = count(s.begin(), s.end(), 'R');
	int c = count(s.begin(), s.end(), 'C');
	if(r == 1 and c == 1 and s[1] < 'A'){
		type1 = true;
	}
	// step 2 : convert the coordinate into other type
	string ans;
	// from type1 to type2
	if(type1){
		int j = 0;
		while( s[j] != 'C') j++;
		int cnum = stoi(s.substr(j+1));
		string a;
		while(cnum){
			int x = cnum%26;
			if(x == 0) x = 26;
			cnum -= x;
			cnum /= 26;
			x--;
			a += (x + 'A');
		}
		reverse(a.begin(), a.end());
		ans += a;
		ans += s.substr(1, j-1);
	}else{// from type2 to type1
		int j = 0;
		while(s[j] >= 'A') j++;
		ans += "R" + s.substr(j) + "C";
		string a = s.substr(0, j);
		int p = 1, b = 0;
		while(a.size()){
			b += ((a.back() - 'A')+1) *p;
			a.pop_back();
			p *= 26;
		}
		ans += to_string(b);
	}
	cout << ans << endl;
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
