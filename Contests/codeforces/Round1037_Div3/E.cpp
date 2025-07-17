#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<i64> p(n), s(n);
		for (int i = 0; i < n; ++i) cin >> p[i];
		for (int i = 0; i < n; ++i) cin >> s[i];

		if (p[n-1] != s[0]) {
			cout << "NO" << el;
			continue;
		}

		i64 g = p[n-1];
		bool acc = true;
		for (int i = 0; i < n; ++i) if (__gcd(p[i],s[i]) != g) {
			acc = false;
			break;
		}

		if (!acc) {
			cout << "NO" << el;
			continue;
		}

		for (int i = 1; i < n; ++i) if (p[i-1] % p[i] != 0) {
			acc = false;
			break;
		}

		if (!acc) {
			cout << "NO" << el;
			continue;
		}

		for (int i = 0; i < n-1; ++i) if (s[i+1] % s[i] != 0) {
			acc = false;
			break;
		}

		if (!acc) {
			cout << "NO" << el;
			continue;
		}

		vector<i64> a(n);		a[0]=p[0], a[n-1]=s[n-1];
		for (int i = 1; i < n - 1; ++i) {
			i64 curG = __gcd(p[i], s[i]);
			a[i] = (p[i] * s[i]) / curG;
		}

		vector<i64> pp(n);	pp[0] = a[0];
		vector<i64> ss(n);	ss[n-1] = a[n-1];
		for (int i = 1; i < n; ++i)
			pp[i] = __gcd(pp[i-1], a[i]);
		for (int i = n-2; i >= 0; --i)
			ss[i] = __gcd(ss[i+1], a[i]);

		if (pp == p && ss == s) cout << "YES" << el;
		else cout << "NO" << el;
	}

	return 0;
}
