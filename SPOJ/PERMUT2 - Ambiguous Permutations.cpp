#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (true) {
        ll n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        ll arr[n + 1];
        arr[0] = 0;
        for (ll i = 1; i < n + 1; i++) {
            cin >> arr[i];
        }
        bool pos = true;
        for (ll i = 1; i < n + 1; i++) {
            if (arr[i] != i && arr[arr[i]] != i) {
                pos = false;
                break;
            }
        }
        if (pos == false) {
            cout << "not ambiguous" << endl;
        }
        else {
            cout << "ambiguous" << endl;
        }
    }
    return 0;
}