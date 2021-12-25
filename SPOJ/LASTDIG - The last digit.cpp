#include <iostream>
using namespace std;
int main()
{
    int t;cin>>t;while(t--){
        long long b;
        int a,temp,curr,ans=1;
        cin>>curr>>b;
        a=curr%10;
        if(b==0){
            ans=1;
            goto ne;
        }
        else if(a==2 || a==3 || a==8 || a==7){
            temp=b%4;
            if(temp==0){temp=4;}
        }
        else if(a==4 || a==9){
            temp=b%2;
            if(temp==0)
                temp=2;
        }
        else{ans=a;}
        for(int i=1;i<=temp;i++){ans*=curr;}
        ans=ans%10;
        ne:
        cout<<ans;
        if(t!=0){cout<<"\n";}
    }
    return 0;
}