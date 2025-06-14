#include <bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i32 t; cin >> t;
	while (t--) {
		i32 n; cin >> n;
		i32 a[n], tx0r = 0;
		for (int i = 0, x; i < n; ++i) cin >> a[i], tx0r ^= a[i];
		if (tx0r == 0) {
			cout << "YES" << el;
			continue;
		}

		i32 cx0r = 0, cnt = 0;
		for (int i = 0; i < n; ++i) {
			cx0r ^= a[i];
			if (cx0r == tx0r) ++cnt, cx0r = 0;
		}

		cout << (cnt >= 3 ? "YES" : "NO") << el;
	}

	return 0;
}

