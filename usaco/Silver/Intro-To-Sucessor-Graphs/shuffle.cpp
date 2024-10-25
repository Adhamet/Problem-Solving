#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	
	ll n;
	cin >> n;

	vector<ll> a(n), cowsAfterShuffle(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= 1;
		cowsAfterShuffle[a[i]] += 1;
	}

	ll ans = n;
	queue<ll> noCows;
	for (int i = 0; i < n; i++) if (cowsAfterShuffle[i] == 0) {
		noCows.push(i);
		ans -= 1;
	}

	while (!noCows.empty()) {
		ll curr = noCows.front();
		noCows.pop();

		if (--cowsAfterShuffle[a[curr]] == 0) {
			noCows.push(a[curr]);
			ans -= 1;
		}
	}

	cout << ans << el;
	return 0;
}
