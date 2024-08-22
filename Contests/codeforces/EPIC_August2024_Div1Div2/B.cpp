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

		bool acc = true;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> b[i];
			
			if (b[i] != a[i]) acc = false;
		}
		
		reverse(a.begin(), a.end());
		if (!acc) {
			acc = true;
			for (int i = 0; i < n; i++) {
				if (b[i] != a[i]) {
					acc = false;
					break;
				}
			}
		}

		if (acc) cout << "Bob\n";
		else cout << "Alice\n";
	}

	return 0;
}
