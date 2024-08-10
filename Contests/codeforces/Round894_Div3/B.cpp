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

		vector<int> b(n);
		for (auto &i: b) cin >> i;

		vector<int> a;
		a.push_back(b[0]);

		for (int i = 1; i < n; i++) {
			if (a.back() <= b[i]) a.push_back(b[i]);
			else {
				a.push_back(1);
				a.push_back(b[i]);
			}
		}

		cout << a.size() << el;
		for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
		cout << el;
	}

	return 0;
}
