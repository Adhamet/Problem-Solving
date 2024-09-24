#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 4e5 + 10;
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;

		int a, b, c;
		if (n % 3 == 2) { 
			a = (n / 3) + 2, b = (n / 3 + 1), c = (n / 3) - 1;
		} else if (n % 3 == 1) {
			a = (n / 3) + 2, b = (n / 3), c = (n / 3) - 1;
		} else a = (n / 3) + 1, b = (n / 3), c = (n / 3) - 1;
		cout << b << " " << a << " " << c << el;
	}
	
	return 0;
}
