#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	if (n % 2 == 0) cout << -1;
	else {
		vector<int> perm(n);
		iota(perm.begin(), perm.end(), 0);
		for (int i = 0; i < 2; i++) {
			for (int num: perm) cout << num << " ";
			cout << el;
		}

		for (int i = 0; i < n; i++) cout << (perm[i] + perm[i]) % n << " ";
	}

	return 0;
}
