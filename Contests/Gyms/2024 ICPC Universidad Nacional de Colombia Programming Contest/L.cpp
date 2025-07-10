#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

bool isSTBG(char ch) {
	if (ch == '0' || ch == '2' || ch == '5' || ch == 'E'
			|| ch == '3' || ch == '1' || ch == '6' ||
			ch == '9' || ch == '8')
		return true;
	return false;
}

bool ok(char a, char b) {
	if (a == '0' && b == '0')
		return true;
	if (a == '2' && b == '2')
		return true;
	if (a == '5' && b == '5')
		return true;
	if (a == 'E' && b == '3')
		return true;
	if (a == '3' && b == 'E')
		return true;
	if (a == '1' && b == '1')
		return true;
	if (a == '6' && b == '9')
		return true;
	if (a == '9' && b == '6')
		return true;
	if (a == '8' && b == '8')
		return true;
	return false;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;	cin >> s;
	i64 ans = 0;
	int l = 0, r = (int)s.size() - 1;
	while (l < r) {
		if (!isSTBG(s[l])) ans += 1;
		if (!isSTBG(s[r])) ans += 1;
		if (isSTBG(s[l]) && isSTBG(s[r])) {
			if (!ok(s[l], s[r])) ans += 1;
		}

		l += 1, r -= 1;
	}

	if (l == r) {
		if (s[l] == '2' || s[l] == '5' || s[l] == '1' || s[l] == '8'
				|| s[l] == '0') {
		} else ans += 1;
	}

	return cout << ans, 0;
}
