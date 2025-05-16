#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        i64 n, m, k;
        cin >> n >> m >> k;
        vector<i64> a(k);
        for (int i = 0; i < k; ++i) cin >> a[i];

        auto canFill = [&](i64 big, i64 small) {
            vector<i64> b = a;
            sort(b.rbegin(), b.rend());
            i64 tot = 0;

            for (int i = 0; i < k; ++i) {
                i64 blocks = b[i] / small;
                if (blocks >= 2) tot += blocks;
            }

            if (big % 2 == 0) return tot >= big;
            else {
                for (int i = 0; i < k; ++i) if (b[i]/small >= 3) return tot >= big;
                return false;
            }
        };

        if (canFill(n, m) || canFill(m, n)) cout << "Yes" << el;
        else cout << "No" << el;
    }

    return 0;
}
