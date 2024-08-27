#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

// const int N = 2e5 + 10;
// const int oo = 1e9 + 20;

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<ll> a(n), b(n);
		for (auto& i: a) cin >> i;
		for (auto& i: b) cin >> i;

		ll ans = LLONG_MAX, curr = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (i <= m - 1) {
				ans = min(ans, a[i] + curr);
			}
			
			curr += min(a[i], b[i]);
		}

		cout << ans << el;
	}
	
  	return 0;
}
