#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

const int N = 500 + 10;
// const int oo = 1e9 + 20;
int ra[N], ca[N], rb[N], cb[N];;
string a[N], b[N];

int main() {
  	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < max(n, m); i++) {
			ra[i] = ca[i] = rb[i] = cb[i] = 0;
		}

		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				(ra[i] += (a[i][j] - '0')) %= 3;
				(ca[j] += (a[i][j] - '0')) %= 3;
				(rb[i] += (b[i][j] - '0')) %= 3;
				(cb[j] += (b[i][j] - '0')) %= 3;
			}
		}

		bool flag = true;
		for (int i = 0; i < max(n, m); i++) {
			flag &= (ra[i] == rb[i]);
			flag &= (ca[i] == cb[i]);
		}

		cout << (flag? "YES" : "NO") << el;
	}
	
  	return 0;
}
