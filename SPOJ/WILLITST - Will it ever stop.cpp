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
    unsigned ll arr[60];
    arr[0]=2;
    for(int i=1; i<60; i++){
        arr[i] = arr[i-1]*2;
    }
    unsigned ll num;
    bool yes=false;
    cin>>num;
    if(num==1){
        cout<<"TAK";
        return 0;
    }
    for(int i=0; i<60; i++){
        if(num==arr[i]){
            yes=true;
            break;
        }
    }
    if(yes==true){
        cout<<"TAK";
    }
    else{
        cout<<"NIE";
    }
    return 0;
}