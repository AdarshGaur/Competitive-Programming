// Author : Adarsh Gaur 

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl "\n"

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.precision(20);
	const int INF = 1e18 + 7;
	multiset<int> s;
	s.insert(-INF);
	int query; cin >> query;
	while(query--){
		int q, x, k, i=1, ans=-1;
		cin >> q;
		if(q == 1){
			cin >> x;
			s.insert(x);
		}else if(q == 2){
			cin >> x >> k;
			auto it = s.upper_bound(x);
			i--;
			while(i<k and it != s.begin()) it--, i++;
			if(it != s.begin()) ans = *it;
			cout << ans << endl;
		}else{
			cin >> x >> k;
			auto it = s.lower_bound(x);
			while(i < k and it != s.end()) it++, i++;
			if( it != s.end() ) ans = *it;
			cout << ans << endl;
		}
	}
	return 0;
}
