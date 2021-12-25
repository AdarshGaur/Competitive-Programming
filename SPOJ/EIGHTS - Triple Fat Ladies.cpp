#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

    ll times; cin >> times; while (times--) {
        unsigned ll k;
        cin >> k;
        ll b, a;
        a = k / 4;
        b = k % 4;
        if (b == 1) {
            b = 192;
        }
        else if (b == 2) {
            b = 442;
        }
        else if (b == 3) {
            b = 692;
        }
        else {
            b = 942;
            a--;
        }
        if (a == 0) {
            cout << b << endl;
        }
        else {
            cout << a << b << endl;
        }
    }
    return 0;
}