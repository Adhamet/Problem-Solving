#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int a[n][m], mxEle = 0;
		vector<int> freq(101, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
				mxEle = max(mxEle, a[i][j]);
				if (mxEle == a[i][j]) freq[mxEle]++;
			}
		}

		vector<int> cmir(n), cmic(m); // cnt of mx in rows, columns
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == mxEle)
					cmir[i]++;
			}
		}

		for (int j = 0; j < m; ++j) {
			for (int i = 0; i < n; ++i) {
				if (a[i][j] == mxEle)
					cmic[j]++;
			}
		}

		bool acc = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				/*cout << "TEST: " << cmir[i] << ' ' << cmic[j] << ' ' << freq[mxEle] << el;*/
				if (a[i][j] == mxEle) {
					if (cmir[i] + cmic[j] - 1 == freq[mxEle]) {
						acc = true;
						break;
					}
				} else {
					if (cmir[i] + cmic[j] == freq[mxEle]) {
						acc = true; 
						break;
					}
				}
			}

			if (acc) break;
		}

		cout << (acc? mxEle - 1: mxEle) << el;
	}

	return 0;
}
