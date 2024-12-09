#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		ll tot = 0, num = 0;;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			tot += s.length();
			if (tot <= m) num += 1;
		}

		cout << num << el;
	}

	return 0;
}
