#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i64 a, b, c, n, m;	cin >> a >> b >> c >> n >> m;
	if (n > m) {
		b += c;
		if (b <= m) {
			if (a + c <= n) cout << a + b;
			else cout << n;
		} else cout << m;
	} else if (n < m) {
		a += c;
		if (a <= n) {
			if (b + c <= m) cout << a + b;
			else cout << m;
		} else cout << n;
	} else {
		if (a + c <= n && b + c <= m) cout << a + b + c;
		else cout << m;
	}

	return 0;
}
