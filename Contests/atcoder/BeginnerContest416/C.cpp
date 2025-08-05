#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

vector<string> s, res;
int n, k, x;

string cur;
void go(int depth) {
	if (depth == k) {
		res.push_back(cur);
		return;
	}
	for (int i = 0; i < n; ++i) {
		cur += s[i];
		go(depth + 1);
		cur.erase(cur.size() - s[i].size());
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k >> x;
	s.resize(n);
	for (int i = 0; i < n; ++i) cin >> s[i];
	go(0);
	sort(res.begin(), res.end());
	return cout << res[x - 1], 0;
}

