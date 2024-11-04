#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string colors = "ROYGBIV";
	int n;
	cin >> n;

	string ans = "";
	for (int i = 0; i < n; i++) ans += colors[i % 7];
	int sz = ans.size();
	for (int i = 0; i < sz; i++) {
		if (ans[(i + 1) % sz] == ans[i]) swap(ans[(i + 4) % sz], ans[(i + 1) % sz]);
		else if (ans[(i + 2) % sz] == ans[i]) swap(ans[(i + 5) % sz], ans[(i + 2) % sz]);
		else if (ans[(i + 3) % sz] == ans[i]) swap(ans[(i + 6) % sz], ans[(i + 3) % sz]);
	}

	cout << ans;
	return 0;
}
