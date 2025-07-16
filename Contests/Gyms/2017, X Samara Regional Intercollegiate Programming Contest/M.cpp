#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define fst first
#define scd second
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;	cin >> n;
	i64 sm = 0;
	vector<i64> a(n);
	for (int i = 0; i < n; i++) cin >> a[i], sm += a[i];

	if (sm < 0 || sm > n-1) {
		cout << "NO" << '\n';
		return 0;
	}

	if (sm == 0) {
		cout << "YES" << '\n';
		return 0;
	}

	set<int> nonzero, zero;
	vector<i64> rem = a;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) zero.insert(i);
		else nonzero.insert(i);
	}

	vector<pair<int, int>> ans;
	for (int kill = 0; kill < sm; kill++) {
		if (nonzero.empty()) return cout << "NO", 0;
		int killer = *nonzero.rbegin();
		if (zero.empty()) return cout << "NO", 0;

		int victim = *zero.rbegin();
		ans.push_back({killer, victim});
		zero.erase(victim);

		rem[killer]--;
		if (rem[killer] == 0) {
			nonzero.erase(killer);
			zero.insert(killer);
		}
	}

	cout << "YES" << el;
	for (auto& x : ans) cout << x.fst + 1 << " " << x.scd + 1 << el;
	return 0;
}
