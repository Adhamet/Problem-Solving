#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'
#define F first
#define S second

// const int N = 36;
// const int oo = 1e9 + 7;

int main() { 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		bool found = false;
		char grid[n][n];
		int startI = 0, startJ = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
				if (!found && grid[i][j] == '1') startI = i, startJ = j, found = true;
			}
		}

		if (grid[startI][startJ + 1] == '1' && grid[startI + 1][startJ] == '1') {
			cout << "SQUARE" << el;
		} else cout << "TRIANGLE" << el;
	}

	return 0;
}
