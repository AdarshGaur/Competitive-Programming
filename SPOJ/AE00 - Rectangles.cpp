#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 100001
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n; cin>>n;
    ll t, ans=0;
    for(t=1; (n/t)>=t ; t++){
        ans = ans + (n/t) - (t-1);
    }
    cout<<ans;
    return 0;
}
