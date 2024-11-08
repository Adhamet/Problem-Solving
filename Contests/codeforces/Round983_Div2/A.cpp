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

		int ones = 0;
		vector<int> a(2 * n);
		for (auto &i: a) {
			cin >> i;
			if (i == 1) ones += 1;
		}	

		if (ones == 0) cout << 0 << " " << 0 << el;
		else cout << ones % 2 << " " << min(n, ones) << el;
	}

	return 0;
}	
