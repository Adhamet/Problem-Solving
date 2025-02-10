#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, vector<int>>> vecs(n);
		for (int i = 0; i < n; ++i) {
			vecs[i].second.resize(m);

			int sum = 0;
			for (int j = 0; j < m; ++j) {
				cin >> vecs[i].second[j];
				sum += vecs[i].second[j];
			}

			vecs[i].first = sum;
		}

		sort(vecs.rbegin(), vecs.rend());

		int sk = 0, si = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				si += vecs[i].second[j];
				sk += si;
			}
		}

		cout << sk << el;
	}

	return 0;
}
