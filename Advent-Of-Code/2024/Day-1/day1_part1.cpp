#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);

	vector<int> left, right;
	int x, y;
	while (cin >> x >> y) {
		left.push_back(x), right.push_back(y);
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	ll tot = 0;
	for (int i = 0; i < left.size(); i++) tot += abs(left[i] - right[i]);
	cout << tot;
	return 0;
}
