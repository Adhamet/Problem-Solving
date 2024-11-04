#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, l;
	cin >> n >> l;
	vector<double> a(n);
	for (auto &i: a) cin >> i;
	sort(a.begin(), a.end());
	double mx = max(a[0], l - a[n - 1]) * 2;
	for (int i = 1; i < n; i++) mx = max(mx, a[i] - a[i - 1]);
	cout << fixed << setprecision(12) << mx / 2.0 << el;
	return 0;
}
