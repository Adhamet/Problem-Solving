#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int lastTrue(int l, int r, function<bool(int)> can) {
	l -= 1;
	
	while (l < r) {
		int mid = l + (r - l + 1) / 2;
		if (can(mid)) l = mid;
		else r = mid - 1;
	}

	return l;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto &i: a) cin >> i;
	sort(a.begin(), a.end());

	int val = lastTrue(1, 2e9, [&](int key) {
		ll ops = 0;
		for (int i = (n - 1) / 2; i < n; i++) ops += max(0, key - a[i]);
		return ops <= k;
	});

	cout << val << el;

	return 0;
}
