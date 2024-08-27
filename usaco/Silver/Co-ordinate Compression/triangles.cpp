#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 1e5;
const int C = 1e4;
const int MOD = 1e9 + 7;

struct Fence {
	int x, y;
	ll heightSum, baseSum;
} fences[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);

	int n;
	cin >> n;

	vector<pair<ll, ll>> xcoords[2 * C + 1], ycoords[2 * C + 1];
	for (int i = 0; i < n; i++) {
		cin >> fences[i].x >> fences[i].y;

		xcoords[fences[i].x + C].push_back({fences[i].y, i});
		ycoords[fences[i].y + C].push_back({fences[i].x, i});
	}

	for (int i = 0; i <= 2 * C; i++) {
		if (xcoords[i].size() > 0) {
			sort(xcoords[i].begin(), xcoords[i].end());
	
			ll currHS = 0;
			for (int j = 1; j < xcoords[i].size(); j++) {
				currHS += (xcoords[i][j].first - xcoords[i][0].first);
			}
	
			fences[xcoords[i][0].second].heightSum = currHS;
			for (int j = 1; j < xcoords[i].size(); j++) {
				currHS += (2 * j - xcoords[i].size()) * (xcoords[i][j].first - xcoords[i][j - 1].first);
				fences[xcoords[i][j].second].heightSum = currHS;
			}
		}
	}

	for (int i = 0; i <= 2 * C; i++) {
		if (ycoords[i].size() > 0) {
			sort(ycoords[i].begin(), ycoords[i].end());
	
			ll currBS = 0;
			for (int j = 1; j < ycoords[i].size(); j++) {
				currBS += (ycoords[i][j].first - ycoords[i][0].first);
			}
	
			fences[ycoords[i][0].second].baseSum = currBS;
			for (int j = 1; j < ycoords[i].size(); j++) {
				currBS += (2 * j - ycoords[i].size()) * (ycoords[i][j].first - ycoords[i][j - 1].first);
				fences[ycoords[i][j].second].baseSum = currBS;
			}
		}
	}

	ll totalArea = 0;
	for (int i = 0; i < n; i++) {
		totalArea += (fences[i].heightSum * fences[i].baseSum) % MOD;
		totalArea %= MOD;
	}
	cout << totalArea << el;
	
	return 0;
}
