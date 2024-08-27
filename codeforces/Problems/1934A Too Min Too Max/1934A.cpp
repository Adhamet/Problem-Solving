#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'
#define F first
#define S second

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);
		for (auto &i: v) cin >> i;
		sort(begin(v), end(v));

		cout << 2 * ( (v[n - 1] + v[n - 2]) - (v[0] + v[1]) ) << el;
	}

	return 0;
}
