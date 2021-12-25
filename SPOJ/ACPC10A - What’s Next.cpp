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
    while(true){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==0 && y==0 && z==0){
            break;
        }
        else{
        	cout<<endl;
        }

        int d, r;
        ll next;

        if((y-x)==(z-y)){
            // case of AP
            d = y-x;
            next = z + d;
            cout<<"AP "<<next;
            continue;
        }
        else{
            // case of GP
            if(x>0 && y>0){
                if(y<x)//decreasing
                {
                    r = (x/y);
                    next = (z/r);
                }
                else  // increasing
                {
                    r = (y/x);
                    next = z*r;
                }
            }
            else if(x<0 && y<0){ // negative numbers
                if(y<x){  //increasing in negative numbers
                    r = (y/x);
                    next = z*r;
                }
                else{    // decreasing in negative numbers
                    r = (x/y);
                    next = (z/r);
                }
            }
            else{
                if(x<0){
                    if(x<z){
                        r = x/y;
                        next = z/r;
                    }
                    else{
                        r = y/x;
                        next = z*r;
                    }
                }
                else{
                    if(x<z){
                        r = y/x;
                        next = z*r;
                    }
                    else{
                        r = y/z;
                        next = z/r;
                    }
                }
            }
            cout<<"GP "<<next;
        }
    }
    return 0;
}