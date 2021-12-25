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
    ll t; cin >> t;
    while (t--) {
        ll r, c;
        cin >> r >> c;
        if (r == 0 || c == 0) {
            cout << endl;
            continue;
        }
        char arr[r][c];
        for (ll i = 0; i < c; i++) {
            arr[0][i] = '*';
            arr[r - 1][i] = '*';
        }
        for (ll i = 0; i < r; i++) {
            arr[i][0] = '*';
            arr[i][c - 1] = '*';
        }
        for (ll i = 1; i < r - 1; i++) {
            for (ll j = 1; j < c - 1; j++) {
                arr[i][j] = '.';
            }
        }
        for (ll i = 0; i < r; i++) {
            for (ll j = 0; j < c; j++) {
                cout << arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}