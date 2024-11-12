#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define fst first
#define scd second
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, t1, t2, k;
	cin >> n >> t1 >> t2 >> k;
	vector<pair<double, int>> ans;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		double c1 = (a * t1) - (double(a * t1 * k) / 100) + (b * t2);
		double c2 = (b * t1) - (double(b * t1 * k) / 100) + (a * t2);
		ans.push_back({-1 * max(c1, c2), i});
	}

	sort(ans.begin(), ans.end());
	for (auto pr: ans) cout << pr.scd <<  " " << fixed << setprecision(2) << -1 * pr.fst << el;
	return 0;
}
