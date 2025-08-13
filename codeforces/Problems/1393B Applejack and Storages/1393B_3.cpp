#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int MXN = 1e5+5;

	int n;	cin >> n;
	vector<int> freq(MXN, 0);
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		freq[x]++;
	}

	int P = 0, Q = 0;
	for (int i = 0; i < MXN; ++i) {
		P += freq[i] / 2;
		Q += freq[i] / 4;
	}

	int q;	cin >> q;
	while (q--) {
		char op;	cin >> op;
		int x;	cin >> x;
		int oldP = freq[x] / 2;
		int oldQ = freq[x] / 4;

		if (op == '+') ++freq[x];
		else --freq[x];

		int newP = freq[x] / 2;
		int newQ = freq[x] / 4;

		P += newP - oldP;
		Q += newQ - oldQ;

		if (Q >= 2 || (Q >= 1 && P >= 4)) cout << "YES" << el;
		else cout << "NO" << el;
	}

	return 0;
}

