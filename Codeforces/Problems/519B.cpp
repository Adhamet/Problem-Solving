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
	
	int n,x;
	cin >> n;

	ll fsum = 0;
	for(int i = 0; i < n; i++) {
		cin >> x;
		fsum += x;
	}
	ll ssum = 0;
	for(int i = 0; i < n-1; i++) {
		cin >> x;
		ssum += x;
	}
	ll tsum = 0;
	for(int i = 0; i < n-2; i++) {
		cin >> x;
		tsum += x;
	}
	cout << (fsum - ssum) << el << (ssum - tsum);
	
    return 0;
}