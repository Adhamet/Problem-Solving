#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

ull pow(ull b, ull p, ull m) {
	if (p == 0) return 1;
	ull sq = pow(b, p/2, m);
	sq = (sq * sq) % m;

	if (p%2 == 1) sq = (sq * b) % m;

	return sq;
}

int main()
{
    // adhamet;

    ull B, P, M;
    while(cin >> B >> P >> M) {
		ull ans = pow(B,P,M);	cout << ans << el;
	}

    return 0;
}
