#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 100001
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        int num=0;
        if( x==0 && y==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        if( x==1 && y==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        if(x%2==0)
        {
            if(y==x)
            {
                num= x*2;
                cout<<num<<endl;
            }
            else if(y==(x-2))
            {
                num= (x-1)*2;
                cout<<num<<endl;
            }
            else
            {
                cout<<"No Number"<<endl;
            }
        }
        else
        {
            if(y==x)
            {
                num=(x*2)-1;
                cout<<num<<endl;
            }
            else if(y==(x-2))
            {
                num=(x*2)-3;
                cout<<num<<endl;
            }
            else
            {
                cout<<"No Number"<<endl;
            }
        }
    }
    return 0;
}