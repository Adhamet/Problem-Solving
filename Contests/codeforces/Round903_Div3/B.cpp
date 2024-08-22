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
		int a, b, c;
		cin >> a >> b >> c;

		int mn = min({a, b, c});
		if (a % mn != 0 || b % mn != 0 || c % mn != 0) cout << "NO" << el;
		else {
			int cnt = 0;
			cnt += (a / mn) + (b / mn) + (c / mn) - 3;
			
			if (cnt <= 3) cout << "YES" << el;
			else cout << "NO" << el;
		}
	}

	return 0;
}
