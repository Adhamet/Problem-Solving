#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'
 
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;	cin >> s;
	int n = (int)s.size();
	
	vector<int> kmp(n, 0);
	for (int i = 1; i < n; ++i) {
		int j = kmp[i - 1];
		while (j > 0 && s[i] != s[j]) j = kmp[j - 1];
		if (s[i] == s[j]) ++j;
		kmp[i] = j;
	}
	
	vector<int> ans;
	for (int k = kmp[n-1]; k > 0; k = kmp[k - 1]) ans.push_back(k);
	reverse(ans.begin(), ans.end());
	for (auto &x: ans) cout << x << ' ';
	return 0;
}
