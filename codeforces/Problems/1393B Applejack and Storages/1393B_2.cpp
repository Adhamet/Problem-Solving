#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int MXN = 1e5+5;

	int n;	cin >> n;
	vector<int> f(MXN), ff(MXN);
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		f[x] += 1;
		ff[f[x]] += 1;
	}


	int q;	cin >> q;
	while (q--) {
		char op;	cin >> op;
		int x;	cin >> x;
		if (op == '+') f[x]++, ff[f[x]]++;
		else ff[f[x]]--, f[x]--;
		if (ff[8] >= 1 || ff[6] >= 1 && ff[2] >= 2 || 
					ff[4] >= 2 || ff[4] >= 1 && ff[2] >= 3)
			cout << "YES" << el;
		else cout << "NO" << el;
	}
	
	return 0;
}
