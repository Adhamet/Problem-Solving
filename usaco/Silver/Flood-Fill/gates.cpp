#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4005;

void setIO(string name = "") {
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	setIO("gates");

	int n;
	string s;
	cin >> n >> s;

	int x = 0, y = 0;
	vector<vector<bool>> fences(MAXN, vector<bool>(MAXN, false));
	fences[2000][2000] = true;

	int cycles = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'N') {
			y += 2;
			if (!fences[2000 + y - 1][2000 + x] && fences[2000 + y][2000 + x]) cycles++;
			fences[2000 + y - 1][2000 + x] = true;
			fences[2000 + y][2000 + x] = true;
		} else if (s[i] == 'S') {
			y -= 2;
			if (!fences[2000 + y + 1][2000 + x] && fences[2000 + y][2000 + x]) cycles++;
			fences[2000 + y + 1][2000 + x] = true;
			fences[2000 + y][2000 + x] = true;
		} else if (s[i] == 'E') {
			x += 2;
			if (!fences[2000 + y][2000 + x - 1] && fences[2000 + y][2000 + x]) cycles++;
			fences[2000 + y][2000 + x - 1] = true;
			fences[2000 + y][2000 + x] = true;
		} else if (s[i] == 'W') {
			x -= 2;
			if (!fences[2000 + y][2000 + x + 1] && fences[2000 + y][2000 + x]) cycles++;
			fences[2000 + y][2000 + x + 1] = true;
			fences[2000 + y][2000 + x] = true;
		}
	}

	cout << cycles << '\n';
	return 0;
}

