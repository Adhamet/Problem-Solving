#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> block(n + 1, n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            block[x] = min(block[x], y - 1);
        }

		int ans = n;
		for (int i = n - 1; i > 0; --i) block[i] = min(block[i], block[i + 1]);
        for (int i = 1; i <= n; i++) ans += (block[i] - i);
        cout << ans << el;
    }

    return 0;
}

