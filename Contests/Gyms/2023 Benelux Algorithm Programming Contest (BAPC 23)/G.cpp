#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define int i64
#define el '\n'

bool areParallel(int x1, int y1, int x2, int y2,
			int x3, int y3, int x4, int y4) {
	int dx1 = x2 - x1, dy1 = y2 - y1;
	int dx2 = x4 - x3, dy2 = y4 - y3;
	return dx1 * dy2 == dy1 * dx2;
}

int __dist(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1, dy = y2 - y1;
	return dx * dx + dy * dy;
}

bool isPerp(int x1, int y1, int x2, int y2,
		int x3, int y3, int x4, int y4) {
	int dx1 = x2 - x1, dy1 = y2 - y1;
	int dx2 = x4 - x3, dy2 = y4 - y3;
	return dx1 * dx2 + dy1 * dy2 == 0;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int x1, y1;		cin >> x1 >> y1;
	int x2, y2;		cin >> x2 >> y2;
	int x3, y3;		cin >> x3 >> y3;
	int x4, y4;		cin >> x4 >> y4;

	int mnX = min({x1,x2,x3,x4});
	int mnY = min({y1,y2,y3,y4});
	int mxX = max({x1,x2,x3,x4});
	int mxY = max({y1,y2,y3,y4});
	int s1 = __dist(x1,y1,x4,y4);
	int s2 = __dist(x2,y2,x3,y3);
	int s3 = __dist(x1,y1,x2,y2);
	int s4 = __dist(x3,y3,x4,y4);
	bool ps1s3 = areParallel(x1,y1,x2,y2,x3,y3,x4,y4);
	bool ps2s4 = areParallel(x1,y1,x4,y4,x2,y2,x3,y3);
	bool allSidesEq = (s1 == s2) && (s2 == s3) && (s3 == s4);
	bool allRightAng = isPerp(x4,y4,x1,y1,x1,y1,x2,y2) &&
				isPerp(x1,y1,x2,y2,x2,y2,x3,y3) &&
				isPerp(x2,y2,x3,y3,x3,y3,x4,y4) &&
				isPerp(x3,y3,x4,y4,x4,y4,x1,y1);

	if (allSidesEq && allRightAng) cout << "square";
	else if (allRightAng) cout << "rectangle";
	else if (allSidesEq && ps1s3 && ps2s4) cout << "rhombus";
	else if (ps1s3 && ps2s4) cout << "parallelogram";
	else if (ps1s3 || ps2s4) cout << "trapezium";
	else {
		bool k1 = (s2 == s4 && s3 == s1);
		bool k2 = (s3 == s2 && s1 == s4);
		if (k1 || k2) cout << "kite";
		else cout << "none";
	}

	return 0;
}
