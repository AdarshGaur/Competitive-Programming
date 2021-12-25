#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define MAX 1000001
#define PI 3.14159265

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //ll t;cin>>t;
    ll dp[5001];
    char num[5001];
    while (true) {
        cin >> num;
        if (num[0] == '0') {
            return 0;
        }
        int l = strlen(num);
        dp[0] = 1;
        if (l == 1) {
            cout << "1" << endl;
            continue;
        }
        dp[1] = 1;
        int c1, c2;
        c2 = num[0] - '0';
        c1 = num[1] - '0';
        if (c1 == 0) {
            if (c2 == 1 || c2 == 2) {
                dp[1] = 1;
            }
            else {
                dp[1] = 0;
            }
        }
        else {
            if (c2 == 1 || (c2 == 2 && c1 <= 6)) {
                dp[1] = 2;
            }
            else {
                dp[1] = 1;
            }
        }
        for (int i = 2; i < l; i++) {
            dp[i] = 0;
            c1 = num[i] - '0';
            c2 = num[i - 1] - '0';
            if (c1 != 0) {
                dp[i] += dp[i - 1];
            }
            if (c2 == 1 || (c2 == 2 && c1 < 7)) {
                dp[i] += dp[i - 2];
            }
        }
        cout << dp[l - 1] << endl;
    }
    return 0;
}