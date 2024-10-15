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

const int MAXN = 100 + 5;
/*const int oo = 1e9 + 20;*/
bool vis[MAXN][MAXN][MAXN];
int MAXK, MAXX, MAXY, M, minDiff = INT_MAX;
void floodfill(int x, int y, int k) {
	if (k > MAXK || vis[x][y][k]) {
		return;
	}

	int m = x + y, pourXY = min(x, MAXY - y), pourYX = min(y, MAXX - x);
	minDiff = min(minDiff, abs(M - m));
	
	vis[x][y][k] = true;
	floodfill(x, MAXY, k + 1);
	floodfill(MAXX, y, k + 1);
	floodfill(0, y, k + 1);
	floodfill(x, 0, k + 1);
	floodfill(x - pourXY, y + pourXY, k + 1);
	floodfill(x + pourYX, y - pourYX, k + 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("pails");
	cin >> MAXX >> MAXY >> MAXK >> M;
	floodfill(0, 0, 0);
	cout << minDiff;
	return 0;
}
