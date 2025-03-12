#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	int32_t n, ans = 0;
	scanf("%d", &n);

	char s[n];
	scanf("%s", s);

	vector<int32_t> f(n + 3, 0), a(n + 3, 0);
	for (int i = 1; i <= n; ++i) f[i] = f[i - 1] + (s[i - 1] == 'F');
	for (int i = n; i >= 1; --i) a[i] = a[i + 1] + (s[i - 1] == 'A');

	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] == 'A') ans += f[i];
		else if (s[i - 1] == 'N') ans += min(f[i], a[i]);
	}

	return printf("%d", ans), 0;
}
