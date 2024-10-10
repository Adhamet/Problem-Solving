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

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// 1 0 1 1 0 1 [pos]
	int n, t, k;
	cin >> n >> t >> k;

	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;

		cout << "? 1 " << mid << el;
		cout.flush();
		
		int res;
		cin >> res;

		if (mid - res >= k) r = mid - 1;
		else l = mid + 1;
	}

	cout << "! " << r + 1 << el;
	cout.flush();
	return 0;
}

