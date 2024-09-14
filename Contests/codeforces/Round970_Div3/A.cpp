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
		int a, b;
		cin >> a >> b;

		if (b % 2 == 1) {
			if (a % 2 == 0 && a != 0) {
				cout << "YES\n";
				continue;
			}
		} else if (b % 2 == 0 && a % 2 == 0) {
			cout << "YES\n";
			continue;
		}

		cout << "NO\n";
	}

	return 0;
}
