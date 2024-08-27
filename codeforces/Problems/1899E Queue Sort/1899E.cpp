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
	ios_base::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);
 
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int mn = INT_MAX, idx = -1;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] < mn) {
				mn = a[i];
				idx = i;
			}
		}

		bool acc = true;
		for (int i = idx + 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				acc = false;
				break;
			}
		}
		cout << (acc ? idx: -1) << el;
	}

	return 0;
}
