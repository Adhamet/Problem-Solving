#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) {
        i64 n, m, k; cin >> n >> m >> k;
		i64 x = k / (2*n);
		k %= (2*n);
		x *= 2;
		if (k <= n) x+=k;
		else x+=(2*n-k);
		cout << x << el;
	}

    return 0;
}

