#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int k, r;
	cin >> k >> r;
	for (int i = 1; i <= 10; i++) {
		int price = i * k;
		if (price % 10 == 0 || price % 10 == r) {
			cout << i << el;
			break;
		}
	}
	
	return 0;
}
