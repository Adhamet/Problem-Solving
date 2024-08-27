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

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	
	int a,b,c,d;	cin >> a >> b >> c >> d;
	int m = max((3*a) / 10, a - (a / 250) * c);
	int v = max((3*b) / 10, b - (b / 250) * d);

	if (m > v) cout << "Misha\n";
	else if (m < v) cout << "Vasya\n";
	else cout << "Tie\n";
    return 0;
}