#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vector<char>> grid(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			grid[i][j] = 'S';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (k > 0 && ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))) {
				grid[i][j] = 'L';
				k -= 1;
			}
		}
	}

	if (k > 0) cout << "NO";
	else {
		cout << "YES" << el;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << grid[i][j];
			}

			cout << el;
		}
	}
	return 0;
}
