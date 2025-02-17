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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());

		int discount = 0, buy = 0;
		for (int i = 0; i < n; i++) {
			a[i] = max(a[i] - discount, 0);
			buy += a[i];
			discount += 1;
		}

		cout << buy << el;
	}

	return 0;
}
