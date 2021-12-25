#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define MAX 100001

using namespace std;

map<ll, ll> dp;

ll solve(ll n)
{
    if (n == 0) {return 0;}

    if (dp[n] != 0) {return dp[n];}

    ll aux = solve(n / 2) + solve(n / 3) + solve(n / 4);

    if (aux > n) {dp[n] = aux;}
    else {dp[n] = n;}

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    while (cin >> n) {
        cout << solve(n) << endl;
    }
    return 0;
}