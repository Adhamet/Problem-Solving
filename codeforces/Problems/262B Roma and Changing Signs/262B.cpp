#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);
	int n, k, x, tot = 0, mn = INT_MAX;
	cin >> n >> k;

	queue<int> q;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x < 0 && k) k--, x*=-1;
		tot += x;
		mn = min(mn, x);
	}

	if (k > 0 && k % 2 != 0) cout << tot - mn - mn << el;
	else cout << tot << el;
	return 0;
}
