#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++) cin >> v[i];

		if (v[1] > n) {
			cout << "NO\n";
			continue;
		}

		vector<int> h;
		for (int i = n; i >= 1; i--) {
			while (h.size() < v[i]) h.push_back(i);
		}

		bool acc = true;
		for (int i = 1; i <= n; i++) {
			if (v[i] != h[i - 1]) {
				acc = false;
			}
		}

		if (acc) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
