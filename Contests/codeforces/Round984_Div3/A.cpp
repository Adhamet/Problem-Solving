#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &i: a) cin >> i;

		bool acc = true;
		for (int i = 1; i < n; i++) {
			int val = abs(a[i] - a[i - 1]);
			if (val != 5 && val != 7) {
				acc = false;
				break;
			}
		}

		cout << (acc ? "YES": "NO") << el;
	}

	return 0;
}
