#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define MAX 100001

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;cin>>t;while(t--){
    ll num;
    cin>>num;
    num = num%10;
    if(num==0){
        cout<<"2";
    }
    else{
        cout<<"1"<<endl<<num;
    }
    return 0;
}