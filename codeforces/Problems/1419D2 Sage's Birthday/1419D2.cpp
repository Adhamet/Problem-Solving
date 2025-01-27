#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i != n - 1 && i % 2 != 0) b.push_back(i);
	}

	if (n == 1 || n == 2) {
		cout << 0 << el;
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		return 0;
	}

	sort(a.begin(), a.end());

	vector<int> c(n);
	int l = 0, r = n - 2;
	for (auto idx: b) {
		if (r <= l) break;
		c[idx] = a[l];
		if (r == n - 2) c[idx - 1] = a[r], c[idx + 1] = a[r + 1];
		else c[idx + 1] = a[r];
		r -= 1, l += 1;
	}

	if (n % 2 == 0) c[n - 1] = a[l];
	for (int i = 0, m = (int)b.size(); i < (m / 2); ++i) {
		swap(c[b[i]], c[b[m - i - 1]]);
	}

	int cnt = 0;
	for (int i = 1; i < c.size() - 1; ++i) {
		if (c[i] < c[i-1] && c[i] < c[i+1]) {
			cnt++;
		}
	}

	cout << cnt << el;
	for (auto num: c) cout << num << ' ', 0;
	return 0;
}
