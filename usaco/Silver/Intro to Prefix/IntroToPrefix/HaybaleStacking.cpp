#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 2e5+10;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> pref(n, 0);
	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		pref[l - 1] += 1, pref[r] -= 1;
	}

	for (int i = 1; i < n; i++) pref[i] += pref[i - 1];
	sort(pref.begin(), pref.end());

	cout << pref[(n / 2)] << el;
	
	return 0;
}
