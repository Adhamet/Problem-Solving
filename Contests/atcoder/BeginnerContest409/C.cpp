#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, l; cin >> n >> l;

	vector<i64> pts(n), freq(l);
	pts[0] = 0;
	freq[0] += 1;
	for (int i = 0; i < n - 1; ++i) {
		int x; cin >> x;
		pts[i+1] = (pts[i] + x) % l;
		freq[pts[i+1]] += 1;
	}

	if (l % 3) return cout << "0", 0;

	i64 ans = 0;
	for (int i = 0; i < (l / 3); ++i)
		ans += (freq[i] * freq[i+(l/3)] * freq[i+(2*(l/3))]);
	return cout << ans, 0;
}
