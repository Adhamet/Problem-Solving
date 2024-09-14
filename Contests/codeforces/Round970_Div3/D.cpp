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
		int n;
		cin >> n;

		vector<int> perm(n), f(n, 0);
		for (int i = 0; i < n; i++) cin >> perm[i], perm[i]--;

		string s;
		cin >> s;

		vector<bool> vis(n, false);
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;

			vector<int> idcs;
			int blacks = 0;

			int j = i;
			while (!vis[j]) {
				vis[j] = true;
				idcs.push_back(j);
				if (s[j] == '0') blacks += 1;
				j = perm[j];
			}

			for (auto i: idcs) f[i] = blacks;
		}

		for (int i = 0; i < n; i++) cout << f[i] << " ";
		cout << el;
	}

	return 0;
}
