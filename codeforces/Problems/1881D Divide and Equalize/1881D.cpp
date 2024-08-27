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

void prime(int x, map<int, int>& mp) {
	while (x % 2 == 0) {
		mp[2] += 1;
		x /= 2;
	}

	for (int i = 3; i <= sqrt(x); i++) {
		while (x % i == 0) {
			mp[i] += 1;
			x /= i;
		}
	}

	if (x > 1) mp[x] += 1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;

			prime(x, mp);
		}

		bool acc = true;
		for (auto itr = mp.begin(); itr != mp.end(); itr++) {
			if (itr->second % n != 0) {
				acc = false;
				break;
			}
		}

		if (acc) cout << "YES" << el;
		else cout << "NO" << el;
	}

	return 0;
}
