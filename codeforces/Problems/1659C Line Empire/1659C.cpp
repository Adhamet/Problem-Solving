#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n, a, b; cin >> n >> a >> b;
        vector<i64> v(n), pref(n+1);
        for (int i = 0; i < n; ++i) cin >> v[i];
        for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + v[i - 1];

        i64 mn = INT64_MAX;
        for (int j = 0; j <= n; ++j) {
            i64 curr;
            if (j == 0) curr = b * (pref[n] - pref[0]);
            else {
                i64 costMv = (a + b) * (v[j-1]);
                i64 costRem = b * ((pref[n]-pref[j]) - v[j-1] * (n-j));
                curr = costMv + costRem;
            }

			mn = min(mn, curr);
        }

        cout << mn << el;
    }

    return 0;
}
