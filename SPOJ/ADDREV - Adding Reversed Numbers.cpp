#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll rev(ll n);

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll numb_first, numb_second;
		cin>>numb_first;
		cin>>numb_second;
		numb_first=rev(numb_first);
		numb_second=rev(numb_second);
		ll sum;
		sum=numb_first+numb_second;
		sum=rev(sum);
		cout<<sum<<"\n";
		
	}
	
	return 0;
}

ll rev(ll n){
	ll temp=0;
	while(n>0){
		temp=(temp*10)+(n%10);
		n/=10;
	}
	return temp;
}