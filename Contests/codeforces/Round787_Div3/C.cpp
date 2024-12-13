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
		string s;
		cin >> s;

		int n = s.size();
		int lastOne = -1, firstZero = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1' && firstZero == -1) lastOne = i;
			else if (s[i] == '0') {
				firstZero = i;
				break;
			}
		}

		if (lastOne != -1 && firstZero != -1) cout << firstZero - lastOne + 1 << el;
		else if (lastOne == -1 && firstZero == -1) cout << n << el;
		else if (lastOne != -1 && firstZero == -1) cout << n - lastOne << el;
		else if (lastOne == -1 && firstZero != -1) cout << firstZero + 1 << el;
	}

	return 0;
}
