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
        int n;
        cin >> n;

        vector<int> a(n);
        map<int, int> freq;
        for (int i = 0; i < n; ++i) cin >> a[i], ++freq[a[i]];

        vector<int> len(n, 0);
        len[0] = (freq[a[0]] == 1);
        for (int i = 1; i < n; ++i) if (freq[a[i]] == 1) {
            len[i] = len[i - 1] + 1;
        }

        int mx = *max_element(len.begin(), len.end());
        if (mx == 0) {
            cout << 0 << el;
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (len[i] == mx) {
                cout << i - len[i] + 2 << ' ' << i + 1 << el;
                break;
            }
        }
    }

    return 0;
}