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
    int t;cin>>t;while(t--){
        char c,s;
        vector<char> signs;
        vector<char> sol;
        int var=0, vsign=0;
        do{
            cin>>c;
            if(c=='('){
                var++;
                continue;
               }
            else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%' || c=='?' || c=='_' || c=='~' || c=='|' || c==';'){
                    signs.push_back(c);
                    vsign++;
            }
            else if(c==')'){
                var--;
                s = signs.at(vsign-1);
                sol.push_back(s);
                signs.pop_back();
                vsign--;
            }
            else{
                sol.push_back(c);
            }
        }while(var!=0);

        for(auto it:sol){
            cout<<it;
        }

        if(t!=0){cout<<endl;}
    }
    return 0;
}