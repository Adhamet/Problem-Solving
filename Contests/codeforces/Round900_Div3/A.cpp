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

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		bool acc = false;
		vector<int> a(n);
		for (auto &i: a) {
			cin >> i;

			if (i == k) acc = true;
		}

		cout << (acc ? "YES" : "NO") << el;
	}
	
	return 0;
}
