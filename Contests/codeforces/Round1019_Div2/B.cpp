#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int ans = n;
		if (s[0] == '1') ans+=1;
		for (int i = 1; i < n; ++i) if (s[i] != s[i-1]) ans+=1;
		if (ans-n >= 3) ans-=2;
		else if (ans-n == 2) ans-=1;
		cout << ans << el;
	}

	return 0;
}
