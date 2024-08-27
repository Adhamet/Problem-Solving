#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 2e5+10;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int cnt = 0;
		while (n >= 4) {
			n -= 4;
			cnt += 1;
		}

		while (n >= 2) {
			n -= 2;
			cnt += 1;
		}

		cout << cnt << el;
	}

	return 0;
}
