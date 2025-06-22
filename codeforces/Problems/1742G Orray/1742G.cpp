#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
        int n;
        cin >> n;
        vector<i64> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

		i64 curr = 0;
        vector<bool> vis(n,false);
        for (int i = 0; i < 31; ++i) {
            int bidx = -1;
            i64 bval = curr;
            for (int j = 0; j < n; ++j) if (!vis[j]) {
                i64 candidate = curr | a[j];
                if (candidate > bval) bval = candidate, bidx = j;
            }

            if (bidx == -1) break;
            vis[bidx] = true;
            curr = bval;
            cout << a[bidx] << ' ';
        }

        for (int j = 0; j < n; ++j) if (!vis[j])
			cout << a[j] << ' ';
        cout << el;
    } return 0;
}

