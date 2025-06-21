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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		vector<pair<int, int>> ops;
		for (int i = 0; i < n; i++) {
			int val = i + 1, pa = -1, pb = -1;
			for (int j = i; j < n; j++) {
				if (a[j] == val) {
					pa = j;
					break;
				}
			}

			if (pa != -1) {
				for (int j = pa - 1; j >= i; j--) {
					swap(a[j], a[j + 1]);
					ops.emplace_back(1, j);
				}
			} else {
				for (int j = i; j < n; j++) {
					if (b[j] == val) {
						pb = j;
						break;
					}
				}
				if (pb == -1) {
					for (int j = 0; j < n; j++) {
						if (b[j] == val) {
							pb = j;
							break;
						}
					}
				}
				if (pb >= i) {
					for (int j = pb - 1; j >= i; j--) {
						swap(b[j], b[j + 1]);
						ops.emplace_back(2, j);
					}
				} else {
					for (int j = pb; j < i; j++) {
						swap(b[j], b[j + 1]);
						ops.emplace_back(2, j);
					}
				}
				swap(a[i], b[i]);
				ops.emplace_back(3, i);
			}
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (b[j] > b[j + 1]) {
					swap(b[j], b[j + 1]);
					ops.emplace_back(2, j);
				}
			}
		}

		cout << (int)ops.size() << el;
		for (auto& [t, i] : ops) cout << t << " " << i + 1 << el;
	}

	return 0;
}


