#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int vp, vd, t, f, c, bijous = 0;
	cin >> vp >> vd >> t >> f >> c;
	double dp = vp * t, dd;
	
	double tt = (dp / (vd-vp));
	while ((tt * vp) + dp < c) {
		bijous += 1;
		dd = vd * tt;
		dp += vp * (f*tt);
		tt = (dp / (vd-vp));
	}

	cout << bijous << el;
	return 0;
}
