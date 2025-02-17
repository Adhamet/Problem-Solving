#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	// if n odd, max = (n/2) + 1 else max = (n/2)
	// or max - n
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int op1, op2;
		if (n % 2 != 0) {
			op1 = (n / 2) + 1;
			op2 = n - op1;
		} else {
			op1 = (n / 2), op2 = (n / 2);
		}

		if (k == op1 || k == op2) cout << "YES" << el;
		else cout << "NO" << el;
	}

	return 0;
}
