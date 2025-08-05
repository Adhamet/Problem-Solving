#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define ld long double
#define EPS 1e-12
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ld Ax, Ay, Bx, By, D;
	cin >> Ax >> Ay >> Bx >> By >> D;
	ld dx = Bx - Ax;
	ld dy = By - Ay;
	ld d2 = dx*dx + dy*dy;
	ld d = sqrt(d2);

	ld S = d2 + 2*D*D;
	ld T = (d2 - D*D) * (d2 - D*D);
	ld disc = S*S - 4*T;
	if (disc < -EPS) return cout << "NO", 0;	
	disc = max<ld>(disc, 0);

	ld X1 = (S + sqrt(disc)) / 2;
	ld X2 = (S - sqrt(disc)) / 2;
	ld X = -1;

	auto valid = [&](ld x) {
		if (x <= EPS) return false;
		ld l = sqrt(x);
		return (l + EPS >= fabsl(d - D) && l <= d + D + EPS);
	};

	if (valid(X1)) X = X1;
	else if (valid(X2)) X = X2;
	if (X < 0) return cout << "NO", 0;

	ld l = sqrt(X);

	ld t = (d2 + D*D - l*l) / (2 * d);
	ld h2 = D*D - t*t;
	if (h2 < -EPS) return cout << "NO", 0;

	h2 = max<ld>(h2, 0);
	ld h = sqrt(h2);
	ld mx = Ax + t * (dx / d);
	ld my = Ay + t * (dy / d);

	ld ox = -dy * (h / d);
	ld oy =  dx * (h / d);

	ld Px = mx + ox;
	ld Py = my + oy;
	ld Qx = mx - ox;
	ld Qy = my - oy;

	cout << "YES" << el;
	cout << fixed << setprecision(8) << Px << ' ' << Py << ' ' << Qx << ' ' << Qy << el;
	return 0;
}
