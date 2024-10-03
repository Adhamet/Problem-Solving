#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	const int target = 32768;
	for (int i = 0; i < n; i++) {
		int x, ans = 100000;
		cin >> x;

		for (int add = 0; add <= 15; add++) {
			int mn = 16;
			
			for (int mul = 0; mul <= 15; mul++) {
				int val = (x + add) << mul;
				
				if ((val % target) == 0) {
					mn = mul + add;
					break;
				}
			}

			ans = min(ans, mn);
		}

		cout << ans << " ";
	}

	return 0;
}
