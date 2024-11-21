#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);

	int n, x;
	cin >> n;
	vector<ll> idx;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 1) idx.push_back(i); // 2 6 7 9
	}

	if (idx.size() == 0) cout << 0 << el;
	else if (idx.size() == 1) cout << 1 << el;
	else {
		vector<ll> nums;
		for (int i = 0; i < idx.size(); i++) {
			if (i == 0 && idx[i] > 0) nums.push_back(i + 1);
			else if (i == idx.size() - 1 && idx[i] < 0) nums.push_back(n - i);
			else if (i != 0) nums.push_back(idx[i] - idx[i - 1]);
		}

		ll ans = 1;
		for (auto num: nums) ans *= num;
		cout << ans;
	}

	return 0;
}
