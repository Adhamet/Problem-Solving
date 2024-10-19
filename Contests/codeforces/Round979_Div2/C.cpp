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
		string s;
		cin >> n >> s;

		bool acc = false;
		if (s[0] == '1' || s[n - 1] == '1') acc = true;
		for (int i = 0; i < n - 1; i++) if (s[i] == '1' && s[i + 1] == '1') {
			acc = true;
		}

		cout << (acc ? "YES": "NO") << el;
	}

	return 0;
}
