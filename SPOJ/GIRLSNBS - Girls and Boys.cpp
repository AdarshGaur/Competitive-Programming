#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 100001
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(true){
        int G, B;
        cin>>G>>B;
        int ans;
        if(G == -1 && B == -1){
            break;
        }
        else{
            cout<<endl;
        }
        if(G==B){        // when both are same
            if(G==0 && B==0){
                cout<<"0";
                continue;
            }
            cout<<"1";
            continue;
        }
        if(G==0){        // when g=0
            cout<<B;
            continue;
        }
        if(B==0){        // when b=0
            cout<<G;
            continue;
        }

        if(B>G){
            if(B%(G+1)==0){
                ans = B/(G+1);
            }
            else{
                ans = (B/(G+1)) + 1;
            }
        }
        else{
            if(G%(B+1)==0){
                ans = G/(B+1);
            }
            else{
                ans = (G/(B+1)) + 1;
            }
        }
        cout<<ans;
    }
    return 0;
}