#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define fs first
#define sc second
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i64 n, m;	cin >> n >> m;
	vector<pair<i64,i64>> exc(m);
	for (int i = 0; i < m; ++i) cin >> exc[i].fs >> exc[i].sc;

	sort(exc.begin(), exc.end(), [](auto &a, auto &b) {
		return (-a.fs+a.sc) > (-b.fs+b.sc);
	});

	i64 tickets = 0;
	for (int i = 0; i < m; ++i) {
		if (n >= exc[i].fs) {
			i64 d = abs(-exc[i].fs + exc[i].sc);
			i64 k = (n - exc[i].fs) / d + 1;
			tickets += k;
			n = n - k * d;
		}
	}

	return cout << tickets, 0;
}

