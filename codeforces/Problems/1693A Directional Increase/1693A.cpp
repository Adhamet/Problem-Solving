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
		cin >> n;

		vector<int> a(n);
		for (auto &i: a) cin >> i;
		
		ll tot = 0;
		bool good = true, onlyZeros = false;
		for (int i = 0; good && i < n; i++) {
			tot += a[i];
			if (tot < 0) good = false;
			else if (tot == 0) onlyZeros = true;

			if (tot > 0 && onlyZeros) good = false;
		}

		if (tot != 0) good = false;
		cout << (good ? "YES" : "NO") << el;
	}

	return 0;
}
