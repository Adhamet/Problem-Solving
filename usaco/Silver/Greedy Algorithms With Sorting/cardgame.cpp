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

	setIO("cardgame");

	int n;
	cin >> n;

	vector<bool> seen(2 * n + 1);
	vector<int> bess1, bess2, els1(n / 2), els2(n / 2);
	for (int i = 0; i < (n / 2); i++) {
		cin >> els1[i];
		seen[els1[i]] = true;
	}

	for (int i = 0; i < (n / 2); i++) {
		cin >> els2[i];
		seen[els2[i]] = true;
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (!seen[i]) {
			if (bess2.size() < (n / 2)) bess2.push_back(i);
			else bess1.push_back(i);
		}
	}

	sort(bess1.begin(), bess1.end(), greater<>());
	sort(bess2.begin(), bess2.end());
	sort(els1.begin(), els1.end(), greater<>());
	sort(els2.begin(), els2.end());

	int ans1 = 0, ans2 = 0, bpos1 = 0, bpos2 = 0;
	for (int i = 0; i < (n / 2); i++) if (bess1[bpos1] > els1[i]) bpos1 += 1, ans1 += 1;
	for (int i = 0; i < (n / 2); i++) if (bess2[bpos2] < els2[i]) bpos2 += 1, ans2 += 1;
	cout << ans1 + ans2;

	return 0;
}

