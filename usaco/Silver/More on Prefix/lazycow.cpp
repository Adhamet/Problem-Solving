#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 21 + 5;
// const int oo = 2e9 + 20;

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(1), cin.tie(0), cout.tie(0);
	setIO("lazy");

	ll n, k;
	cin >> n >> k;
	ll nn = 2 * n - 1;

	vector<vector<ll>> diamond(nn, vector<ll>(nn, - 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> diamond[i + j][n - i + j - 1];
		}
	}

	vector<vector<ll>> pref(nn + 1, vector<ll>(nn + 1));
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < nn; j++) {
			int val = max(diamond[i][j], 0LL);
			pref[i + 1][j + 1] = (val + pref[i + 1][j] + pref[i][j + 1] - pref[i][j]);
		}
	}

	ll mostGrass = 0;
	for (int i = k; i < nn - k; i++) {
		for (int j = k; j < nn - k; j++) {
			if (diamond[i][j] == -1) continue;

			mostGrass = max(mostGrass, pref[i + k + 1][j + k + 1] - pref[i + k + 1][j - k]
										- pref[i - k][j + k + 1] + pref[i - k][j - k]);
		}
	}

	if (k >= n) mostGrass = pref[nn][nn];
	cout << mostGrass << el;
	
	return 0;
}
