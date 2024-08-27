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

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	setIO("pairup");

	int n;
	cin >> n;

	vector<array<int, 2>> cows(n);
	for (int i = 0; i < n; i++) cin >> cows[i][1] >> cows[i][0];
	sort(cows.begin(), cows.end());

	int l = 0, r = n - 1, ans = 0;
	while (l < r) {
		ans = max(ans, cows[l][0] + cows[r][0]);

		if (--cows[l][1] == 0) l += 1;
		if (--cows[r][1] == 0) r -= 1;
	}
	cout << ans << el;

	return 0;
}
