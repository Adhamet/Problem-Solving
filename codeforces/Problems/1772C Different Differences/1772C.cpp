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

	int t;
	cin >> t;

	while (t--) {
		int k, n;
		cin >> k >> n;
		
		for (int mid = k; mid >= 1; mid--) {
			ll a[k];

			a[0] = 1;
			for (int j = 1; j < mid; j++) a[j] = a[j - 1] + j;
			for (int j = mid; j < k; j++) a[j] = a[j - 1] + 1;

			if (a[k - 1] <= n) {
				for (auto ele: a) cout << ele << " ";
				break;
			}
		}

		cout << el;
	}

	return 0;
}
