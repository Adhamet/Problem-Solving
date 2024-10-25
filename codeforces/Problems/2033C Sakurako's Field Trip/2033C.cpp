#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		vector<ll> a(n);
		for (auto &i: a) cin >> i;

		for (int i = 1; i < (n / 2); i++) {
			if (a[i] == a[i - 1] || a[n - i - 1] == a[n - i]) swap(a[i], a[n - i - 1]);
		}

		ll cnt = 0;
		for (int i = 0; i < n - 1; i++) if (a[i] == a[i + 1]) {
			cnt += 1;
		}

		cout << cnt << el;
	}

	return 0;
}
