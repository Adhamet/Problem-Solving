#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

ull gcd(int a, int b) {
	while (b) { a %= b, swap(a, b); }
	return a;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	while (cin >> n && n) {
		int cnt = 0;
		vector<int> a(n);
		for (auto &i: a) cin >> i;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int g = gcd(a[i], a[j]);
				if (g == 1) cnt += 1;
			}
		}
		
		int pairs = n * (n - 1) / 2;
		if (cnt != 0) cout << fixed << setprecision(6) << sqrt((6.0 * pairs) / cnt) << el; 
		else cout << "No estimate for this data set." << el;
	}
	
	return 0;
}
