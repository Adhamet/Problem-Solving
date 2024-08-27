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

ull nCr(int n, int r) {
	if(r > n) return 0;
	r = max(r, n-r);
	ull c = 1, i = r + 1, div = 1;
	while(i <= n) {
		c *= i;		i++;
		c /= div;	div++;
	}
	return c;
}

int main()
{
    adhamet;

	int n,m;
	while(cin >> n >> m) {
		if(n == 0 && m == 0) return 0;
		cout << n << " things taken " << m << " at a time is ";
		cout << nCr(n,m) << " exactly.\n";
	}
	
    return 0;
}