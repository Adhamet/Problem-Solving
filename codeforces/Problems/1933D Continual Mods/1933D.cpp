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

		vector<int> vec(n);
		for (auto& i: vec) cin >> i;

		sort(begin(vec), end(vec));

		if (vec[0] != vec[1]) {
			cout << "YES" << el;
			continue;
		}
		
		bool possible = false;
		for (int i = 0; i < n; i++) {
			if ((vec[i] % vec[0]) != 0) {
				possible = true;
			}
		}

		if (possible) cout << "YES" << el;
		else cout << "NO" << el;
	}

	return 0;
}
