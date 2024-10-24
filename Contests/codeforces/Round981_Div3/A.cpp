#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fst first
#define scd second
#define el '\n'
#define MOD 1000000007

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int MAXN = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int x = 0, i = 1;
		bool turn = 0; // 0 s, 1 k;
		while (abs(x) <= n) {
			int move = (2 * i) - 1;
			if (!turn) x -= move;
			else x += move;
			i += 1;
			turn = !turn;
		}

		cout << (turn ? "Sakurako": "Kosuke") << el;
	}

	return 0;
}
