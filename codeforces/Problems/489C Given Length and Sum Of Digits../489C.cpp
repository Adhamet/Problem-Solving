#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int m, s;
	cin >> m >> s;
	string str(m, '0'), t(m, '0');

	if (m == 1 && s == 0) cout << str << " " << str;
	else if (s > m * 9 || s == 0) cout << -1 << " " << -1 << el;
	else {
		int num = 0, j = m - 1;
		while (num < s) {
			if (num + 9 > s) str[j] = (s - num) + '0', num = s;
			else str[j] = '9', num += 9;
			if (num < s) j -= 1;
		}

		if (j > 0) str[0] = '1', str[j] -= 1;
		
		num = 0, j = 0;
		while (num < s) {
			if (num + 9 > s) t[j] = (s - num) + '0', num = s;
			else t[j] = '9', j += 1, num += 9;
		}

		cout << str << " " << t;
	}

	return 0;
}
