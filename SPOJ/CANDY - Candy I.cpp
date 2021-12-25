#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 100001
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int packets=0;
    while(true){
        cin>>packets;
        if(packets == -1){
            break;
        }
        int candy[packets];
        ll sum=0, temp, ans=0;
        for(int i=0; i<packets; i++){
            cin>>candy[i];
            sum += candy[i];
        }
        if( sum%packets != 0){
            cout<<"-1"<<endl;
            continue;
        }
        else{
            temp = sum/packets;
        }

        for(int i=0; i<packets; i++){
            if(temp>candy[i]){
                    ans += temp - candy[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}