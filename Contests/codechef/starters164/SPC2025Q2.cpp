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
		int n, ved, varun;
		cin >> n >> ved >> varun;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			varun += x;
			mx = max(mx, x);
		}

		varun -= mx, ved += mx;
		if (ved > varun) cout << "Ved" << el;
		else if (varun > ved) cout << "Varun" << el;
		else cout << "Equal" << el;
	}

	return 0;
}
