#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'
#define MAXN 1074
int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);
	vector<int> ans(MAXN);
	int n, k, l, r, sall, sk, ones, rem;
	cin >> n >> k >> l >> r >> sall >> sk;
	ones = sk % k;
	for (int i = 0; i < k; i++) {
		ans[i] = sk / k + (ones > 0);
		ones -= 1;
	}

	rem = sall - sk, ones = rem % (n - k);
	if (k != n) for (int i = k; i < n; i++) {
		ans[i] = rem / (n - k) + (ones > 0);
		ones -= 1;
	}

	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}
