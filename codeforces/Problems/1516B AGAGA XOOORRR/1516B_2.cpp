#include <bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i32 t; cin >> t;
	while (t--) {
		i32 n; cin >> n;
		vector<i32> pf(n+1,0);
		for (int i = 1; i <= n; ++i) cin >> pf[i], pf[i]^=pf[i-1];
		if (pf[n] == 0) {
			cout << "YES" << el;
			continue;
		}

		bool acc = false;
		for (int i = 1; i <= n; ++i) {
			for (int j = i+1; j <= n; ++j) {
				if (pf[i] == (pf[j]^pf[i]) && pf[i] == (pf[n]^pf[j])) {
					acc = true;
					break;
				}
			}

			if (acc) break;
		}

		cout << (acc? "YES" : "NO") << el;
	}

	return 0;
}


