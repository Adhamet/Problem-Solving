#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<i64> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        i64 diff = a[1] - a[0];
        bool acc = true;
        for (int i = 2; i < n; i++) if (a[i] - a[i-1] != diff) {
			acc = false;
			break;
        }

        if (!acc) {
            cout << "NO\n";
            continue;
        }

        i64 num = 1LL * n * a[1] - 1LL * (n - 1) * a[0];
        if (num < 0) {
            cout << "NO\n";
            continue;
        }

        if (num%(n+1) != 0) {
            cout << "NO\n";
            continue;
        }

        i64 ans = (num/(n+1)) - diff;
		cout << ((ans >= 0)? "YES": "NO") << el;
    }

    return 0;
}
