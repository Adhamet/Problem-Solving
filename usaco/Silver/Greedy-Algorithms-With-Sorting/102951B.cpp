#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, x;
	cin >> n >> x;

	vector<int> a(n);
	for (auto &i: a) cin >> i;
	sort(a.begin(), a.end());

	int cnt = 0;
	for (int i = 0; i < n && x >= a[i]; i++) x -= a[i], cnt += 1;
	cout << cnt << el;

	return 0;
}
