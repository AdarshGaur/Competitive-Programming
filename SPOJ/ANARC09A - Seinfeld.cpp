#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define mod 1000000007  //10^9 +7
#define MAX 100001      //10^5 +1
#define PI (3.141592653589)
#define ps(x,y) fixed<<setprecision(y)<<x
#define rep(i,a,b) for(int i=a;i<b;i++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cnt = 0;
    string exp;
    cin >> exp;
    while (exp[0] != '-') {
        cnt++;
        int bracket = 0, ans = 0;
        int n = exp.length();
        for (int i = 0; i < n; i++) {
            if (exp[i] == '{') {
                bracket++;
            } else {
                bracket--;
                if (bracket == -1) {
                    ans++;
                    bracket = 1;
                }
            }
        }
        ans += (bracket / 2);
        cout << cnt << ". " << ans << endl;
        cin >> exp;
    }
    return 0;
}