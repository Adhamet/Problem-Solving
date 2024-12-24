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
        int n, q;
        cin >> n >> q;
        vector<int> a(n), pref(n + 1, 0), ones(n + 1, 0);
        for (int i = 0; i < n; i++) {
			cin >> a[i];
			pref[i + 1] = pref[i] + a[i];
			ones[i + 1] = ones[i] + (a[i] == 1);
		}

        while (q--) {
            int l, r;
            cin >> l >> r;
            int sum = pref[r] - pref[l - 1];
			int cnt = ones[r] - ones[l - 1];
			if (r - l + 1 <= 1 || (r - l + 1) + cnt > sum) cout << "NO" << el;
            else cout << "YES" << el;
        }
    }

    return 0;
}

