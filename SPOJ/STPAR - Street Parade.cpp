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

    //ll times;cin>>times;
    while (true) {
        int n; cin >> n;
        if (n == 0) {
            return 0;
        }
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> street;
        street.push_back(0);
        int pos = 1, p = 0;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] == pos) {
                ///let go
                pos++;
            }
            else {
                if (street[p] == pos) {
                    street.pop_back();
                    pos++;
                    p--;
                    i--;
                }
                else {
                    street.push_back(arr[i]);
                    p++;
                }
            }
        }
        for (int i = p; i > 0; i--) {
            if (street[i] != pos) {
                ans = false;
                break;
            }
            pos++;
        }
        if (ans == true) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
    return 0;
}