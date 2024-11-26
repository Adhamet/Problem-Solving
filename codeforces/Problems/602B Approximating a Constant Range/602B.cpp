#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i: a) cin >> i;

	int l = 0, r = 0, ans = 0;
	int m = a[0], M = a[0];
	while (r < n) {
		m = min(m, a[r]);
		M = max(M, a[r]);

		while (M - m > 1) {
			if (a[l] == m) m = *min_element(begin(a) + l + 1, begin(a) + r + 1);
			if (a[l] == M) M = *max_element(begin(a) + l + 1, begin(a) + r + 1);
			l += 1;
		}

		ans = max(ans, r - l + 1);
		r += 1;
	}

	cout << ans << el;
	return 0;
}
