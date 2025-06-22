#include <bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define el '\n'

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    i32 res = 0;
    for (int x = 0; x <= n; ++x) {
        auto it = lower_bound(a.begin(), a.end(), x);
        i32 cnt = a.end() - it;
        if (cnt >= x) res = x;
    }

	return cout << res, 0;
}

