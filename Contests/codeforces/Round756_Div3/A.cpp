#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // make sure an even exists
        bool evenExists = false;
        for (char &c : s) if ((c - '0') % 2 == 0) {
            evenExists = true;
            break;
        }

        if (!evenExists) {
            cout << -1 << el;
            continue;
        }

        int n = (int)s.size();
        if (s[n - 1] % 2 == 0) cout << 0 << el;
        else if (s[0] % 2 == 0) cout << 1 << el;
        else cout << 2 << el;
    }

    return 0;
}