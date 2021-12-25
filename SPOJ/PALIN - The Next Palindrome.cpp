#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define MAX 1000001

using namespace std;

void palin(string& s)
{
    ll len = s.length();
    ll flag = 1;
    for (ll i = 0; i < len; i++) {
        if (s[i] != '9') {
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        s[0] = '1';
        for (ll i = 1; i < len; i++) {
            s[i] = '0';
        }
        s = s + "1";
    }
    else {
        ll temp, z;
        for (ll i = 0; i < len / 2; i++) {
            if (s[i] > s[len - i - 1]) {
                flag = -1;
            }
            else if (s[i] < s[len - i - 1]) {
                flag = 1;
            }
            s[len - i - 1] = s[i];
        }
        if (flag == 0 || flag == 1) {
            if (len % 2 == 0) {
                temp = (len / 2) - 1;
            }
            else {
                temp = len / 2;
            }
            z = 0;
            while (s[temp - z] == '9') {
                s[temp - z] = '0';
                s[len - 1 - temp + z] = '0';
                z++;
            }
            s[temp - z]++;
            s[len - 1 - temp + z] = s[temp - z];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string p;
    ll t; cin >> t;
    while (t--)
    {
        cin >> p;
        palin(p);
        cout << p << endl;
    }
    return 0;
}