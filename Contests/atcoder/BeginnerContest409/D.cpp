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
		string s;
		cin >> n >> s;
		int l = 0;
		while (l < n - 1 && s[l] <= s[l+1]) ++l;
		int r = l + 1;
		while (r < n && s[r] <= s[l]) ++r;
		rotate(s.begin() + l, s.begin() + l + 1, s.begin() + r);
		cout << s << el;
	}

	return 0;
}

