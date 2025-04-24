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
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];

        bool acc = true;
        vector<int> ans;
        int i = 0, j = 0;
        while ((int)ans.size() < n + m) {
            if (i != n && a[i] == 0) {
                ans.push_back(0);
                k += 1, i += 1;
            } else if (j != m && b[j] == 0) {
                ans.push_back(0);
                k += 1, j += 1;
            } else if (i != n && a[i] <= k) {
                ans.push_back(a[i]);
                i += 1;
            } else if (j != m && b[j] <= k) {
                ans.push_back(b[j]);
                j += 1;
            } else {
                cout << -1 << el;
                acc = false;
                break;
            }
        }
        
        if (acc) {
            for (auto &x: ans) cout << x << ' ';
            cout << el;
        }
    }

    return 0;
}