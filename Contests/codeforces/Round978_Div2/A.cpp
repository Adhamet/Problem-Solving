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
		int n, r;
		cin >> n >> r;

		vector<int> a(n);
		for (auto &i: a) cin >> i;

		int happy = 0, putalone = 0, rr = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) putalone += 1;
			else {
				if (a[i] % 2 == 0) rr += a[i] / 2, happy += a[i];
				else rr += (a[i] - 1) / 2, happy += (a[i] - 1), putalone += 1;
			}
		}

		happy += putalone;
		if (r - rr == 1 && putalone == 2) happy -= 2;
		else while (putalone > (r - rr)) happy -= (putalone % (r - rr)) * 2, putalone -= 2;
		cout << happy << el;
	}

	return 0;
}
