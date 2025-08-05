#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define ld long double
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ld L, B;	cin >> L >> B;
	if (!(B > 0 && 2*L > B)) return cout << -1, 0;
	ld D = 4*L*L - B*B;
	ld sq = sqrt(D);
	ld R = (L*L) / sq;
	ld r = (B * sq) / (4*L + 2*B);
	ld val = R * (R - 2*r);
	if (val < 0) val = 0;
	ld d = sqrt(val);
	return cout << fixed << setprecision(9) << d, 0;
}

