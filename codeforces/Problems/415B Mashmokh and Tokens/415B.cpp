#include <bits/stdc++.h>
using ull = unsigned long long;
#define el '\n'
int main() {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0);
	ull n, a, b;
	std::cin >> n >> a >> b;

	std::vector<ull> ans(n);
	for (int i = 0; i < n; i++) {
		std::cin >> ans[i];
		if ((ans[i] * a) % b == 0) ans[i] = 0;
		else {
			ull tmpVal = (ans[i] * a) / b;
			tmpVal *= b;
			ans[i] = ((ans[i] * a) - tmpVal);
		}
	}

	for (ull &num: ans) std::cout << num << " ";
	return 0;
}
