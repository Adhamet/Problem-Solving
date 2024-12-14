#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

    int n, s, tot = 0;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], tot += a[i];

    if (tot < s) s %= tot;

    vector<int> pref(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        pref[i] = pref[i - 1] + a[(i - 1) % n];
    }

	int l = 0, r = 1;
	while (r <= 2 * n) {
		while (pref[r] - pref[l] > s) l += 1;
		if (pref[r] - pref[l] == s) return cout << "Yes" << el, 0;
		r += 1;
	}

    cout << "No" << el;
    return 0;
}

