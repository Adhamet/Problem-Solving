#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int oo = 1e9;
	int n, k;
	cin >> n >> k;
	string left, right;
	cin >> left >> right;

	vector<vector<int>> time(2, vector<int> (n + 2, oo));
	queue<array<int, 3>> q;
	time[0][1] = 0;
	q.push({0, 1, 0});

	bool accepted = false;
	while (!q.empty()) {
		int wall = q.front()[0];
		int c = q.front()[1];
		int t = q.front()[2];
		int nc, nt, nwall = 1 - wall;
		q.pop();

		// move up
		nc = c + 1, nt = t + 1;
		if (nc > n) return cout << "YES", 0;
		if (nc > nt) {
			if (wall == 0) {
				if (left[nc - 1] == '-' && time[0][nc] > nt) {
					time[0][nc] = nt;
					q.push({0, nc, nt});
				}
			} else {
				if (right[nc - 1] == '-' && time[1][nc] > nt) {
					time[1][nc] = nt;
					q.push({1, nc, nt});
				}
			}
		}

		// move down
		nc = c - 1;
		if (nc >= 1 && nc > nt) {
			if (wall == 0) {
				if (left[nc - 1] == '-' && time[0][nc] > nt) {
					time[0][nc] = nt;
					q.push({0, nc, nt});
				}
			} else {
				if (right[nc - 1] == '-' && time[1][nc] > nt) {
					time[1][nc] = nt;
					q.push({1, nc, nt});
				}
			}
		}

		// jump to other side
		nc = c + k;
		if (nc > n) return cout << "YES", 0;
		if (nc > nt) {
			if (nwall == 0) {
				if (left[nc - 1] == '-' && time[0][nc] > nt) {
					time[0][nc] = nt;
					q.push({0, nc, nt});
				}
			} else {
				if (right[nc - 1] == '-' && time[1][nc] > nt) {
					time[1][nc] = nt;
					q.push({1, nc, nt});
				}
			}
		}
	}

	return cout << "NO", 0;
}
