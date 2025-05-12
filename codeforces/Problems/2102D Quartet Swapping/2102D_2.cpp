#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		set<int> o, e;
		vector<int> pos(n+1, 0), a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			pos[a[i]] = i;
			if (i & 1) o.insert(a[i]);
			else e.insert(a[i]);
		}

		function<void(int, int)> aswap = [&](int idx1, int idx2) {
			if (idx1 == n - 1 || idx2 == n - 1) return;
			pos[a[idx1]] = idx2, pos[a[idx1+1]] = idx2 + 1;
			pos[a[idx2]] = idx1, pos[a[idx2+1]] = idx1 + 1;
			swap(a[idx1], a[idx2]), swap(a[idx1+1], a[idx2+1]);
		};

		for (int i = 0; i < n - 3; ++i) {
			if (i & 1) {
				int best = *o.begin();
				o.erase(o.begin());
				if (pos[best] == n - 1) {
					if (i < n - 4) aswap(n-2, n-4);
					else break;
				}
				aswap(i, pos[best]);
			} else {
				int best = *e.begin();
				e.erase(e.begin());
				if (pos[best] == n - 1) {
					if (i < n - 4) aswap(n-2, n-4);
					else break;
				}
				aswap(i, pos[best]);
			}
		}

		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		cout << el;
	}

	return 0;
}
