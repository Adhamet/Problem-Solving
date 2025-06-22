#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 2e5+5;

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, l, r; cin >> n >> l >> r;
	string s; cin >> s;

	if (l == r) {
		for (int i = 0; i < l; ++i) {
			string t = "";
			for (int j = i; j < n; j += l) t += s[j];
			sort(t.begin(), t.end());
			for (int j = i, k = 0; j < n; j += l) s[j] = t[k++];
		}
	} else if (l <= n / 2) {
		sort(s.begin(), s.end());
	} else {
		string t = "";
		for (int i = 0; i < n; ++i) if (i >= l || i <= n - l - 1) t += s[i];
		sort(t.begin(), t.end());
		for (int i = 0, k = 0; i < n; ++i)
			if (i >= l || i <= n - l - 1) s[i] = t[k++];
	}

	return cout << s, 0;
}

