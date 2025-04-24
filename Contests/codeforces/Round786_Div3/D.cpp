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
        for (int i = n - 2; i >= 0; i -= 2) if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        bool denied = false;
        for (int i = 0; i < n - 1; ++i) if (a[i] > a[i + 1]) {
            denied = true;
            break;
        }

        cout << (denied ? "NO" : "YES") << el;
    }

    return 0;
}