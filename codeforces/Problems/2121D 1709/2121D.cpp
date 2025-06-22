#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define pii pair<int,int>
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
	
		vector<pii> ops;
		for (int i = 0; i < n; ++i) if (a[i] > b[i]) {
			ops.emplace_back(3, i);
			swap(a[i],b[i]);
		}

		auto fix = [&](vector<int>& vec, int op) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n - 1; ++j) {
					if (vec[j] > vec[j+1]) {
						ops.emplace_back(op, j);
						swap(vec[j], vec[j+1]);
					}
				}
			}
			assert(is_sorted(vec.begin(), vec.end()));
		};

		fix(a, 1), fix(b, 2);
		cout << (int)ops.size() << el;
		for (auto& [x, y]: ops) cout << x << ' ' << y + 1 << el;
	}

	return 0;
}
