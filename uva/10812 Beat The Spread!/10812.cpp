#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int s, d;
		cin >> s >> d;
		int a = (s + d) / 2, b = s - a;
		if (d > s || (s + d) % 2 != 0) cout << "impossible" << el;
		else cout << max(a, b) << " " << min(a, b) << el;
	}

	return 0;
}
