#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s; cin >> s;
	int n = (int)s.size();

	int m; cin >> m;
	multiset<int> ms, dist;
	ms.insert(0), ms.insert(m);

	for (int i = 1; i < n; ++i) if (s[i]!=s[i-1]) {
		auto itr = ms.upper_bound(i)--;
		dist.insert(i - *itr);
	}

	return 0;
}
