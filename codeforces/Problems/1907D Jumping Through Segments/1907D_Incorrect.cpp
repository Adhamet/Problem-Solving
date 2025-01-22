#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define fs first
#define sc second
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, mxR = 0;
		cin >> n;
		vector<pair<int, int>> segs(n);
		for (int i = 0; i < n; ++i) {
			cin >> segs[i].fs >> segs[i].sc;
			mxR = max(mxR, segs[i].sc);		
		}

		auto doI = [&](pair<int, int> a, pair<int, int> b) -> bool { // do intersect:
			if ((a.fs <= b.sc && a.sc >= b.fs) || (b.fs <= a.sc && b.sc >= a.fs)) return true;
			return false;
		};

		auto can = [&](int k) -> bool {
			pair<int, int> curr = {0, k};

			for (int i = 0; i < n; ++i) {
				int l = segs[i].fs, r = segs[i].sc;


				cout << curr.fs << " " << curr.sc << " bef" << el;
				cout << l << " " << r << " this" << el;
				if (doI(segs[i], curr)) {
					cout << curr.fs << " " << curr.sc << " aft" << el;
					continue;
				} else if (r < curr.fs) {
					curr.sc = curr.fs;
					curr.fs = curr.fs - k;
					if (!doI(segs[i], curr)) return false;
				} else if (curr.sc < l) {
					curr.fs = curr.sc;
					curr.sc = curr.sc + k;
					if (!doI(segs[i], curr)) return false;
				}

				cout << curr.fs << " " << curr.sc << " aft" << el;
			}

			return true;
		};

		int l = 1, r = mxR, ans = mxR;
		while (l--) {
			int mid = (l + r) >> 1;
			if (can(4)) r = mid - 1, ans = 4;
			else l = mid + 1;
		}

		cout << ans << el;
	}

	return 0;
}
