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

		vector<int> b(n + 1);
		for (int i = 1; i < n; i++) cin >> b[i];

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			a[i] = b[i] | b[i + 1];
		}

		bool acc = true;
		for (int i = 1; i < n; i++) {
			if (b[i] != (a[i - 1] & a[i])) {
				acc = false;
			}
		}

		if (acc) {
			for (int &i: a) cout << i << " ";
			cout << el;
		} else cout << -1 << el;
	}

	return 0;
}
