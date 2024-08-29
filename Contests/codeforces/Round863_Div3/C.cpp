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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> b(n - 1), a(n);
		for (auto &i: b) cin >> i;

		if (n == 2) {
			cout << b[0] << " " << b[0] << el;
			continue;
		}

		a[0] = b[0], a[n - 1] = b[n - 2];
		for (int i = 1; i < n - 1; i++) a[i] = min(b[i], b[i - 1]);
		for (auto i: a) cout << i << " ";
		cout << el;
	}

	return 0;
}
