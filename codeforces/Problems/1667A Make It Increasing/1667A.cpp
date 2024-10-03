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

	int n;
	cin >> n;
	
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		ll prev = 0, sum = 0;
		for (int j = i - 1; j >= 1; j--) {
			prev += a[j] - prev % a[j];
			sum += prev / a[j];
		}

		prev = 0;
		for (int j = i + 1; j <= n; j++) {
			prev += a[j] - prev % a[j];
			sum += prev / a[j];
		}

		ans = min(ans, sum);
	}

	cout << ans << el;

	return 0;
}
