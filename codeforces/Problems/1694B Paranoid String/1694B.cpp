#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		ll ans = 0;
		for (int i = 1; i < n; i++) if (s[i] != s[i - 1]) ans += i;
		cout << ans + n << el;
	}

	return 0;
}
