#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);

	vector<ull> left, right;
	ull x, y;
	while (cin >> x >> y) {
		left.push_back(x), right.push_back(y);
	}

	map<ull, ull> mp;
	int n = left.size(), m = right.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (left[i] == right[j]) mp[left[i]] += 1;
		}
	}

	ull tot = 0;
	for (auto item: mp) tot += (item.first * item.second);
	cout << tot << el;
	return 0;
}
