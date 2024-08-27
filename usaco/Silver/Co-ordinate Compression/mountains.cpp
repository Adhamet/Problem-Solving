#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

struct Mountain {
	int x, y, left, right;

	bool operator<(const Mountain &b) {
		if (left == b.left) return y > b.y;
		return left < b.left;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);

	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	
	int n;
	cin >> n;
		
	vector<Mountain> mountains(n);

	for (int i = 0; i < n; i++) {
		cin >> mountains[i].x >> mountains[i].y;
		mountains[i].left = mountains[i].x - mountains[i].y;
		mountains[i].right = mountains[i].x + mountains[i].y;
	}

	sort(mountains.begin(), mountains.end());

	int peaks = 0, mxRight = -1;
	for (int i = 0; i < n; i++) {
		if (mountains[i].right > mxRight) {
			peaks++;
			mxRight = mountains[i].right;
		}
	}
	cout << peaks << el;
	
	return 0;
}
