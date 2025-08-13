#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, l, r;	cin >> n >> l >> r;

	int list = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;	cin >> a >> b;
		if (a <= l && b >= r) list++;
	}

	return cout << list, 0;
}
