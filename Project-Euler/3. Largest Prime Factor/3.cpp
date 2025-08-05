#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	i64 num = 600851475143, ans = 2;
	int cnt = 0;
	for (i64 i = 2; i * i <= num; ++i)
		while (num % i == 0) num /= i, ans = i;
	if (num > 1) ans = num;
	return cout << ans, 0;
}
