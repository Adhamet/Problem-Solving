#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

const int MAXN = 20;
vector<vector<char>> image(MAXN, vector<char>(MAXN));
vector<vector<bool>> vis(MAXN, vector<bool>(MAXN));

struct PCL {
	int i1, j1, i2, j2;

	bool isInside(PCL other) {
		return i1 >= other.i1 && i2 <= other.i2 && j1 >= other.j1 && j2 <= other.j2;
	}
};

int imin, imax, jmin, jmax;
void floodfill(int i, int j, char color) {
	if (i < imin || j < jmin || i > imax || j > jmax || vis[i][j] || image[i][j] != color) {
		return;
	}

	vis[i][j] = true;
	floodfill(i + 1, j, color);
	floodfill(i - 1, j, color);
	floodfill(i, j + 1, color);
	floodfill(i, j - 1, color);
}

bool isPCL(int i1, int j1, int i2, int j2) {
	vector<int> regionCnt(26);
	imin = i1, imax = i2, jmin = j1, jmax = j2;

	for (int i = i1; i <= i2; i++) {
		for (int j = j1; j <= j2; j++) {
			if (!vis[i][j]) {
				char currColor = image[i][j];
				regionCnt[currColor - 'A']++;
				floodfill(i, j, currColor);
			}
		}
	}

	fill(vis.begin(), vis.end(), vector<bool>(MAXN));

	int cnt = 0;
	bool colWithOne = false, colWithMore = false;
	for (int i = 0; i < regionCnt.size(); i++) {
		if (regionCnt[i] != 0) cnt += 1;
		if (regionCnt[i] == 1) colWithOne = true;
		if (regionCnt[i] > 1) colWithMore = true;
	}

	return (cnt == 2 && colWithOne && colWithMore);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("where");
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> image[i][j];
		}
	}

	vector<PCL> pclList;
	for (int i1 = 0; i1 < n; i1++) {
		for (int j1 = 0; j1 < n; j1++) {
			for (int i2 = 0; i2 < n; i2++) {
				for (int j2 = 0; j2 < n; j2++) {
					if (isPCL(i1, j1, i2, j2)) {
						pclList.push_back({i1, j1, i2, j2});

					}
				}
			}
		}
	}

	int pclCnt = 0;
	for (int i = 0; i < pclList.size(); i++) {
		bool valid = true;
		for (int j = 0; j < pclList.size(); j++) {
			if (i == j) continue;
			if (pclList[i].isInside(pclList[j])) {
				valid = false;
				break;
			}
		}

		pclCnt += valid;
	}

	cout << pclCnt;
	return 0;
}
