#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
		
	int s, a, b, x;	std::cin >> s >> a >> b >> x;
	int ans = 0;
	for (int i = 0; i < x; ++i) {
		int aa = i % (a + b);
		if (aa < a) ans += s;
	}

	return std::cout << ans, 0;
}
