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

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, x;
	cin >> n >> x;

	vector<ll> a(n);
	for (auto &i: a) cin >> i;

	ll sum = 0;
	int l = 0, r = 0, cnt = 0;
	while (r < n) {
		sum += a[r];
		while (sum > x) sum -= a[l++];

		if (sum == x) cnt += 1;
		r += 1;
	}
	cout << cnt << el;


	return 0;
}
