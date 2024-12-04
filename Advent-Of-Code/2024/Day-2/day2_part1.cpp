#include <bits/stdc++.h>
#include <sstream>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);

	int safes = 0;
	string s;
	while (getline(cin, s)) {
		istringstream iss(s);

		int num;
		vector<int> a;
		while (iss >> num) a.push_back(num);

		int n = a.size();
		bool inc = false, ok = true;
		if (a[0] < a[1]) inc = true;
		for (int i = 0; i < n - 1; i++) {
			int diff = abs(a[i] - a[i + 1]);
			if (inc) {
				if (!(a[i] < a[i + 1]) || !(diff >= 1) || !(diff <= 3)) {
					ok = false;
					break;
				}
			} else {
				if (!(a[i] > a[i + 1]) || !(diff >= 1) || !(diff <= 3)) {
					ok = false;
					break;
				}
			}
		}

		if (ok) safes += 1;
	}

	cout << safes << el;
	return 0;
}
