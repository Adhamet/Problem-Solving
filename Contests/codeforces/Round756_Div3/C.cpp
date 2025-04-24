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
        for (int i = 0; i < n; ++i) cin >> a[i];
        if (a[0] != n && a[n-1] != n) cout << -1 << el;
        else {
            for (int i = n-1; i >= 0; --i) cout << a[i] << ' ';
            cout << el;
        }
    }

    return 0;
}
