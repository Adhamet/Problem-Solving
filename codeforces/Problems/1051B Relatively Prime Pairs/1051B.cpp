#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	ull l, r;
	cin >> l >> r;
	cout << "YES" << el;
	while (l + 1 <= r) {
		cout << l << " " << l + 1 << el;
		l += 2;
	}

	return 0;
}
