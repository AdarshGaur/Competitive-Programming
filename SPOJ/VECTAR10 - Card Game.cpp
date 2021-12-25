#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl "\n"
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(ll t){
    ll x=t, temp=0;
    if( (t&(t-1))==0 ){
        cout<<t<<endl;
        return;
    }
    while(x){
        x>>=1;
        temp++;
    }
    temp--;
    int y = t - (1<<temp);
    y<<=1;
    cout<<y<<endl;
}

int main()
{
    fast_cin();
    ll t;
    cin>>t;
    while(t){
     //cout << "Case #" << it+1 << ": ";
        solve(t);
        cin>>t;
    }
    return 0;
}